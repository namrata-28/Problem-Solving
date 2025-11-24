// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int firstContainer = 0, lastContainer = height.size()-1;
//         int maxWater = 0;
//         while(firstContainer<lastContainer){
//             int smallHeight = (height[firstContainer] < height[lastContainer]) ? height[firstContainer] : height[lastContainer];
//             int currentWater = smallHeight*(lastContainer-firstContainer);
//             if(currentWater>maxWater){
//                 maxWater = currentWater;
//             }
//             if(height[firstContainer]<=height[lastContainer]){
//                 firstContainer++;
//             } else{
//                 lastContainer--;
//             }
//         }
//         return maxWater;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            maxArea = max(maxArea, min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};