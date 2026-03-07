class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0, r = height.size()-1;

        while(l < r) {
            int width = r - l;
            maxArea = max(maxArea, min(height[l],height[r]) * width);
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};