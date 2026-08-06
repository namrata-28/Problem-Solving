// Brute Force Approach - TLE - TC = O(n1+n2) SC = O(n1+n2)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> arr;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                arr.push_back(nums1[i++]);
            } else{
                arr.push_back(nums2[j++]);
            }
        }

        while(i < n1) arr.push_back(nums1[i++]);
        while(j < n2) arr.push_back(nums2[j++]);

        int n = n1+n2;
        if(n % 2 == 1) return arr[n/2];
        return (double) ((double)arr[n/2] + (double)arr[n/2 - 1]) / 2.0;
    }
};
