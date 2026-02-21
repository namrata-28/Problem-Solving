// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minprice = INT_MAX;
//         int maxprofit = 0;
//         for (int i = 0; i < prices.size(); i++) {
//             if (prices[i] < minprice)
//                 minprice = prices[i];
//             else if (prices[i] - minprice > maxprofit)
//                 maxprofit = prices[i] - minprice;
//         }
//         return maxprofit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};