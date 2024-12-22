class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left, right, maxlen = 0;
        
        for (left = 0, right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            
            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            maxlen = max(maxlen,right-left+1);

        }
        
        return maxlen;
    }
};