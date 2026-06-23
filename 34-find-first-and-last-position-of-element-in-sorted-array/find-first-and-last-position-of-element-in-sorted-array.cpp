class Solution {
public:
    int lowerBound(vector<int>& nums, int size, int target) {
        int ans = size;
        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int size, int target) {
        int ans = size;
        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return {-1, -1};
        int firstPos = lowerBound(nums, size, target);
        if(firstPos == size || nums[firstPos] != target ) return {-1, -1};
        return {firstPos, upperBound(nums, size, target) - 1};
    }
};