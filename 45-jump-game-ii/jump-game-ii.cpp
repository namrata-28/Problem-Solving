class Solution {
public:
    int jump(vector<int>& nums) {
        int totalJump = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;

        for (int i = 0; i < n - 1; ++i) {
            curFar = max(curFar, i + nums[i]);

            if (i == curEnd) {
                totalJump++;
                curEnd = curFar;
            }
        }

        return totalJump;
    }
};