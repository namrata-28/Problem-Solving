// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i = 0 ; i < nums.size()-1; i++){
//             if(nums[i]==nums[i+1]){
//                 return true;
//             }
//         }
//         return false;
//     }
// }; // O(n log n ) using sorting

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashNums;
        for(int i = 0 ; i < nums.size(); i++){
            if(hashNums.find(nums[i])!=hashNums.end()){
                return true;
            }
            hashNums.insert(nums[i]);
        }
        return false;
    }
};
// O(n) O(n) using hashset