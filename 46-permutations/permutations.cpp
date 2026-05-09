class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr = {};
        solve(curr, nums);
        return ans;
    }

    void solve(vector<int>& curr,vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                solve(curr, nums);
                curr.pop_back();
            }
        }
    }
};