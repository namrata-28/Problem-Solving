class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        if(nums.size()==1) return;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                if(i != insertPos) {
                    swap(nums[i],nums[insertPos]);
                }
                insertPos++;
            }
        }
    }
};