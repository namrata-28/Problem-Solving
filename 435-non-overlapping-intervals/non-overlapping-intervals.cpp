class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int count = 0;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(ans.back()[1] > intervals[i][0]){
                count += 1;
                ans.back()[1] = min(intervals[i][1],ans.back()[1]);
            } else{
                ans.push_back(intervals[i]);
            }
        }
        return count;
    }
};