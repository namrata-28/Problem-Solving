//Using Sorting Approach
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         return nums[n/2];
//     }
// };
// TC:O(nlogn)

//Moore's Voting Algorithm
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int majority,count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(count)
//             {
//                 count+=(nums[i]==majority ? 1 : -1);
//             }
//             else
//             {
//                 majority=nums[i];
//             }
//         }
//         return majority;
//     }
// };
// TC:O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};