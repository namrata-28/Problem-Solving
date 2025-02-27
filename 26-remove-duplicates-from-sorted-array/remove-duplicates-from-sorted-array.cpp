class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j]!=nums[insertIndex]) {
                nums[insertIndex+1] = nums[j];
                insertIndex++;
            }
        }
        return insertIndex+1;
    }
};