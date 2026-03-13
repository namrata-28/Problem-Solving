class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, count  = 0;

        unordered_map<int,int> remFreq;
        remFreq[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum % k;
            if(rem < 0) rem += k;

            if(remFreq.count(rem)) {
                count += remFreq[rem];
            }

            remFreq[rem] += 1;
        }

        return count;
    }
};