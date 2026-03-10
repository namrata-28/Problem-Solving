class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = k-1;
        int count = 0;
        long long sum = 0;

        for(int i = l; i <= r; i++){
            sum += arr[i];
        }

        int avg = sum/k;
        if(avg>=threshold) count++;

        for(int i=k;i<arr.size();i++){
            sum += arr[i];
            sum -= arr[i-k];
            avg = sum/k;
            if(avg>=threshold) count++;
        }

        return count;
    }
};