class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int currentSum = 0;
        unordered_map<int, int> prefixSumCount;

        prefixSumCount[0] = 1;
        for (int num : nums) {
            currentSum += num;

            if (prefixSumCount.count(currentSum - k)) {
                count += prefixSumCount[currentSum - k];
            }

            prefixSumCount[currentSum] += 1;
        }
        return count;
    }
};