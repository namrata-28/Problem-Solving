class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        for (int num : nums) {
            total = (total + num) % p;
        }

        if(total == 0) return 0;

        unordered_map<int,int> mp; // rem, idx

        mp[0] = -1;

        int curr = 0, res = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;

            int need = (curr - total + p) % p;

            if(mp.count(need)) {
                res = min(res, i -mp[need]);
            }

            mp[curr] = i;
        }

        return res == nums.size() ? -1 : res;
    }

};