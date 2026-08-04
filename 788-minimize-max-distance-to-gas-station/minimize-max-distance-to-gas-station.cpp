// Brute force approach - TLE - O(n) * O(k)

// class Solution {
// public:
//     double minmaxGasDist(vector<int>& stations, int k) {
//         int n = stations.size();
//         vector<int> howMany(n-1, 0);
//         for(int gasStations = 1; gasStations <= k; gasStations++){
//             long double maxSection = -1;
//             int maxInd = -1;
//             for(int i = 0; i < n-1; i++){
//                 long double diff = (stations[i+1] - stations[i]);
//                 long double sectionLen = diff / (long double) (howMany[i] + 1);
//                 if(sectionLen > maxSection){
//                     maxSection = sectionLen;
//                     maxInd = i;
//                 }
//             }
//             howMany[maxInd]++;
//         }

//         long double maxAns = -1;
//         for(int i = 0; i < n-1; i++){
//             long double diff = (stations[i+1] - stations[i]);
//             long double sectionLen = diff / (long double) (howMany[i] + 1);
//             maxAns = max(maxAns, sectionLen);
//         }
//         return maxAns;
//     }
// };

// Better approach - using priority queue

// class Solution {
// public:
//     double minmaxGasDist(vector<int>& stations, int k) {
//         int n = stations.size();
//         vector<int> howMany(n-1, 0);

//         priority_queue <pair<long double, int>> pq;
//         for(int i = 0; i < n-1; i++){
//             pq.push({stations[i+1]-stations[i] , i});
//         }

//         for(int gasStations = 1; gasStations <= k; gasStations++){
//             auto tp = pq.top(); 
//             pq.pop();
//             int secInd = tp.second;
//             howMany[secInd]++;

//             long double iniDiff = stations[secInd + 1] - stations[secInd];
//             long double newSecLen = iniDiff / (long double) (howMany[secInd] + 1);
//             pq.push({newSecLen, secInd});
//         }

//         return pq.top().first;
//     }
// };

// optimal approach - TC - O(N*log(Len)) + O(N) - sc - O(1)

class Solution {
private:
    // Returns how many gas stations are needed
    // if maximum allowed distance is 'dist'
    int numberOfGasStationsRequired(long double dist, vector<int>& stations) {
        int cnt = 0;
        int n = stations.size();

        for (int i = 1; i < n; i++) {
            long double gap = stations[i] - stations[i - 1];

            int numberInBetween = gap / dist;

            // If gap is exactly divisible, one less station is needed
            if (gap == dist * numberInBetween) {
                numberInBetween--;
            }

            cnt += numberInBetween;
        }

        return cnt;
    }

public:
    double minmaxGasDist(vector<int>& stations, int k) {

        int n = stations.size();

        // Search space:
        // low = 0
        // high = maximum existing gap
        long double low = 0;
        long double high = 0;

        for (int i = 1; i < n; i++) {
            high = max(high, (long double)(stations[i] - stations[i - 1]));
        }

        // Precision upto 1e-6
        long double diff = 1e-6;

        while (high - low > diff) {

            long double mid = low + (high - low) / 2.0;

            int cnt = numberOfGasStationsRequired(mid, stations);

            if (cnt > k) {
                // Need more than k stations -> distance is too small
                low = mid;
            } else {
                // Possible with <= k stations -> try smaller distance
                high = mid;
            }
        }

        return high;
    }
};