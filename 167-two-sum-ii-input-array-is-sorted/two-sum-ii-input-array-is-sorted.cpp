class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        vector<int> ans(2);

        while(i<j){
            int currentSum = numbers[i]+numbers[j];
            if(currentSum==target){
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            };
            if(currentSum<target){
                i++;
            } else{
                j--;
            }
        }
        
        return ans;
    }
};