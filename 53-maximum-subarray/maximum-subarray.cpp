// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//     long long prefix = 0;
//     long long minPrefix = 0;   // minimum prefix seen so far
//     long long maxSum = LLONG_MIN;

//     for (int num : nums) {
//         prefix += num;

//         // Maximum subarray ending here
//         maxSum = max(maxSum, prefix - minPrefix);

//         // Update minimum prefix
//         minPrefix = min(minPrefix, prefix);
//     }

//     return (int)maxSum;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numsSize = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < numsSize; i++) {
            currSum = max(currSum+nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};