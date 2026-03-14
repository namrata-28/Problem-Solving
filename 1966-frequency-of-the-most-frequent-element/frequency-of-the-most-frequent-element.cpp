class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int maxfreq = 0;
        long sum = 0;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while((long)nums[r]*(r-l+1) - sum > k) {
                sum -= nums[l];
                l++;
            }

            maxfreq = max(maxfreq, r-l+1);
        }

        return maxfreq;

    }
};