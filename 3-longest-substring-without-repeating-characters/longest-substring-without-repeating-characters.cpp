class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int maxlen = 0;
        unordered_set<char> uniqueChars;
        for(int i = 0; i < size; i++) {
            int count = 0;
            for(int j = i ; j < size; j++) {
                if(uniqueChars.find(s[j])==uniqueChars.end()) {
                    uniqueChars.insert(s[j]);
                    count++;
                } else {
                    break;
                }
                maxlen = max(maxlen,count);
            }
            uniqueChars.clear();
        }
        return maxlen;
    }
};