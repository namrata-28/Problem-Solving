class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsHash;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target-nums[i];

            if(numsHash.find(complement)!=numsHash.end()) {
                return{numsHash[complement], i};
            }
            numsHash[nums[i]] = i;
        }
        return { };
    }
};