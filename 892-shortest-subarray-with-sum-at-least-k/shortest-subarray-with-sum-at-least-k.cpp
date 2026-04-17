class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        deque<int> dq;
        int shortestLen = INT_MAX;

        for(int i = 0; i <= n; i++) {
            
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                shortestLen = min(shortestLen, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return shortestLen == INT_MAX ? -1 : shortestLen;
    }
};