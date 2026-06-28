class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;
            // check if left part in sorted
            if(nums[low] <= nums[mid]) {
                // check if present within the range
                if(nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } // check in right part
            else {
                // check if present within the range
                if(nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};