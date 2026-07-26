// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for(int num : arr){
//             if(num <= k){
//                 k++;
//             } else{
//                 break;
//             }
//         }
//         return k;
//     }
// };

//  bs +  math tricky
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low + k;
    }
};