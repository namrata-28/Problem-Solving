class Solution {
public:
    vector<vector<int>> memo;

    bool helper(int index, int remaining, vector<int>& nums) {
        if (remaining == 0)
            return true;

        if (index >= nums.size() || remaining < 0)
            return false;

        if (memo[index][remaining] != -1)
            return memo[index][remaining];

        bool include = helper(index + 1, remaining - nums[index], nums);
        bool exclude = helper(index + 1, remaining, nums);

        return memo[index][remaining] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        memo.assign(nums.size(), vector<int>(target + 1, -1));

        return helper(0, target, nums);
    }
};