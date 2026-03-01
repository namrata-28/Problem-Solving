// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> numsHash;

//         for(int i = 0; i < nums.size(); i++) {
//             int complement = target-nums[i];

//             if(numsHash.find(complement)!=numsHash.end()) {
//                 return{numsHash[complement], i};
//             }
//             numsHash[nums[i]] = i;
//         }
//         return { };
//     }
// };

// Logic:

    //value:index combination we store value as a key and index as  value in hashmap 
    // Tc: O(n) sc: O(n) n stands for unique elements in array

//TC = O(n)
//sc = O(n)



 //sorting approach

    // vector<pair<int,int>> arr;
    // for(int i = 0;i < nums.size(); i++) {
    //     arr.push_back({nums[i], i});
    // }

    // sort(nums.begin(),nums.end());
    // int i = 0, j = nums.size()-1;

    // while(i<j) {
    //     int sum = arr[i].first + arr[j].first;
    //     if(sum==target)
    //         return {arr[i].second,arr[j].second};
    //     else if(sum>target) j--;
    //     else i++;
    // }
    // return { };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsMap;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(numsMap.find(complement) != numsMap.end()) {
                return{numsMap[complement],i};
            }

            numsMap[nums[i]] = i;
        }

        return { };
    }
};