class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int count = 0;
        int sum = 0;

        unordered_map<int,int> sumfreq;

        sumfreq[0] = 1;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            int targetSum = sum-goal;

            if(sumfreq.count(targetSum)) {
                count += sumfreq[targetSum];
            }

            sumfreq[sum] += 1;
        }

        return count;
    }
};