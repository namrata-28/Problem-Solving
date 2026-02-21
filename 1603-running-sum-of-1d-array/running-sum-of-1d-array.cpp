class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currSum = 0;
        vector<int> finalSum;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            finalSum.push_back(currSum);
        }
        return finalSum;
    }
};