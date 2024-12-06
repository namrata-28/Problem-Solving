class Solution {
public:

    bool isStrictlyIncreasing(vector<int>& nums, int start, int k) {
        for(int i = start; i < start+k-1; i++){
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(n<k*2) return false;
        if(k==1) return true;
        for(int i = 0; i <= n-k*2; i++){
            if(isStrictlyIncreasing(nums,i,k) && isStrictlyIncreasing(nums,i+k,k)){
                return true;
            }
        }
        return false;
    }
};