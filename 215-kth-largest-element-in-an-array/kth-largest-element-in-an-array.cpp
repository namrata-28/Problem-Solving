// max heap = n log n
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;

//         for(int num : nums) {
//             pq.push(num);
//         }

//         for(int i = 0; i < k-1; i++) {
//             pq.pop();
//         }

//         return pq.top();
//     }
// };

// min heap = n log k
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) {
            pq.push(num);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};