class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int count = 0;
        int currSum = 0;

        unordered_map<int,int> prefixSumCount;

        prefixSumCount[0] = 1;

        for(int num : nums) {
            currSum += num;

            int targetSum = currSum-goal;

            if(prefixSumCount.count(targetSum)) {
                count += prefixSumCount[targetSum];
            }

            prefixSumCount[currSum] += 1;
        }

        return count;
    }
};