class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(),nums.end());

        int longestSequence = 0;
        for(int num : nums_set) {
            if(!nums_set.count(num-1)) {
                int currNum = num; // starting element of consecutive sequence
                int currSequence = 1; // initialize counter for any current sequence at a time
                while(nums_set.count(currNum+1)) {
                    currNum += 1; // keep building sequence
                    currSequence += 1; // keep incrementing counter
                }

                // once the sequence building logic breaks i.e No more next consecutive element exists for curr Num
                longestSequence = max(longestSequence, currSequence); // Update longestSequence lenght
            }
        }

        return longestSequence; // after all the elements in the set explored return the length of longestSequence
    }
};