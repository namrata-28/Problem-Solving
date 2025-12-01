class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i] != nums[i-1]) {
                twoSum(nums, i , ans);
            }
        }
        return ans;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ans) {
        int lo = i + 1, hi = nums.size() - 1;
        while(lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if(sum < 0 ){
                lo++;
            } else if(sum > 0) {
                hi--;
            } else {
                ans.push_back({nums[i], nums[lo], nums[hi]});
                lo++;
                hi--;
                while(lo < hi && nums[lo] == nums[lo-1]) lo++;
                while(lo < hi && nums[hi] == nums[hi+1]) hi--;
            }
        }
    }
};