class Solution {
public:
    int maxArea(vector<int>& height) {
        int firstContainer = 0, lastContainer = height.size()-1;
        int maxWater = 0;
        while(firstContainer<lastContainer){
            int smallHeight = (height[firstContainer] < height[lastContainer]) ? height[firstContainer] : height[lastContainer];
            int currentWater = smallHeight*(lastContainer-firstContainer);
            if(currentWater>maxWater){
                maxWater = currentWater;
            }
            if(height[firstContainer]<height[lastContainer]){
                firstContainer++;
            } else{
                lastContainer--;
            }
        }
        return maxWater;
    }
};