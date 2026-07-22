class Solution {
private:
    int findMax(vector<int>& piles) {
        int maxElem = INT_MIN;
        for(int num : piles){
            maxElem = max(maxElem, num);
        }
        return maxElem;
    }
    long long calculateTotalHours(vector<int> &piles, int hourly){
        long long totalHours = 0;
        for(int num : piles){
            totalHours += ceil((double)num / hourly);
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high) {
            int mid = low + (high - low)/2;
            long long speedK = calculateTotalHours(piles, mid);
            if(speedK <= h){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};