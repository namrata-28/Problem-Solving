class Solution {
public:
    bool binarySearh(vector<int> &arr, int target){
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target == arr[mid]) return true;
            else if(target < arr[mid]) high = mid - 1;
            else  low= mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0]<=target && target <= matrix[i][n-1]){
                if(binarySearh(matrix[i], target)) 
                    return true;
            }
        }
        return false;
    }
};
