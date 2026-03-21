class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalt = 0;
        int currsum = 0;
        for(int altgain : gain) {
            currsum += altgain;
            maxalt = max(currsum,maxalt);
        }
        return maxalt;
    }
};