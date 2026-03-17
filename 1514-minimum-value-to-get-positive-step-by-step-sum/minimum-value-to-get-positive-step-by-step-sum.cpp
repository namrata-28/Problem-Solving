class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int minPrefixSum = INT_MAX;
        int sum = 0;

        for(int num : nums) {
            sum += num;
            minPrefixSum = min(minPrefixSum, sum);
        }

        if(minPrefixSum >= 1)
        {
            return 1;
        } else {
            return abs(minPrefixSum) + 1;
        }
    }
};