class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates,vector<int>& curr, int target, int currSum, int i) {
        if(currSum==target) {
            ans.push_back(curr);
            return;
        }

        if(i >= candidates.size() || currSum > target) {
            return;
        }

        curr.push_back(candidates[i]);
        solve(candidates, curr, target, currSum+candidates[i], i);
        
        curr.pop_back();
        
        solve(candidates, curr, target, currSum, i + 1);
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, curr, target, 0, 0);

        return ans;
    }
};