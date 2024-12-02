class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<vector<int>> &answer, vector<int> currAns){
        if(idx==nums.size()){
            answer.push_back(currAns);
            return;
        }
        currAns.push_back(nums[idx]);
        helper(nums,idx+1,answer,currAns);
        currAns.pop_back();
        helper(nums,idx+1,answer,currAns);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currAns;
        helper(nums,0,answer,currAns);
        return answer; 
    }
};