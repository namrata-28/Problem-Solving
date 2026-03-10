class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> u;

        for(int i = 0; i < nums.size(); i++) {
            if(u.count(nums[i])) return true;

            u.insert(nums[i]);

            if(u.size()>k) {
                u.erase(nums[i-k]);
            }
        }
        return false;
    }
};