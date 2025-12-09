class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int left = 0, currentSum = 0, res = INT_MAX;
      for(int right = 0; right < nums.size(); right++) {
        currentSum += nums[right];

        while(currentSum >= target) {
            res = min(res, right-left+1); // min length
            currentSum -= nums[left];
            left++;
        }
      }  
      return res == INT_MAX ? 0 : res;
    }
};