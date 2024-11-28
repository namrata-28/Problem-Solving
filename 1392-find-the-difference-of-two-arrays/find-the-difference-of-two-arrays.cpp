class Solution {
public:
    vector<int> getDistinctElements(vector<int>& nums1, vector<int>& nums2){
            unordered_set<int> setNums2;
            unordered_set<int> distElements;

            for(int num : nums2){
                setNums2.insert(num);
            }

            for(int num : nums1){
                if(setNums2.find(num) == setNums2.end()){
                    distElements.insert(num);
                }
            }

        return vector<int> (distElements.begin(), distElements.end());

    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getDistinctElements(nums1,nums2),getDistinctElements(nums2,nums1)};
    }
};