class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxlen = 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) nums[i] = -1;
            
            sum += nums[i];

            if(mp.count(sum)) {
                maxlen = max(maxlen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }

        }

        return maxlen;
    }
};