class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        for(int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        double maxSum = currSum;
        for(int j = k; j < nums.size(); j++) {
            currSum = currSum - nums[j-k] + nums[j];
            maxSum = max(maxSum, currSum);
        }
        return maxSum/k;
    }
};