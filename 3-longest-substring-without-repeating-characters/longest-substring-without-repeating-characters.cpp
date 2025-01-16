// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> charSet;
//         int l = 0;
//         int res = 0;

//         for (int r = 0; r < s.size(); r++) {
//             while (charSet.find(s[r]) != charSet.end()) {
//                 charSet.erase(s[l]);
//                 l++;
//             }
//             charSet.insert(s[r]);
//             res = max(res, r - l + 1);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> unique;
        int left = 0, result = 0;

        for(int right = 0; right < s.size(); right++) {
            if(unique.find(s[right]) != unique.end()) {
                left = max (unique[s[right]] + 1, left);
            }
            unique[s[right]] = right;
            result = max(result, right-left+1);
        }
        return result;
    }
};