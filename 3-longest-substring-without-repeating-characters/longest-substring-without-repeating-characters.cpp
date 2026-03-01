// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         vector<int> hash(256,-1);

//         int l = 0, r = 0, maxlen = 0;
//         while( r < n) {
//             if(hash[s[r]] != -1) {
//                 l = max(hash[s[r]] + 1, l);
//             }

//             int len = r - l + 1;
//             maxlen = max(maxlen,len);
//             hash[s[r]] = r;
//             r++;
//         }
//         return maxlen;
//     }  
// };

// My bruteforce

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int size = s.size();
//         int maxlen = 0;
//         unordered_set<char> uniqueChars;
//         for(int i = 0; i < size; i++) {
//             int count = 0;
//             for(int j = i ; j < size; j++) {
//                 if(uniqueChars.find(s[j])==uniqueChars.end()) {
//                     uniqueChars.insert(s[j]);
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             maxlen = max(maxlen,count);
//             uniqueChars.clear();
//         }
//         return maxlen;
//     }
// };


// Striver's brute force

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxlen = 0;

//         for(int i = 0; i < n; i++) {
//             vector<int> hash(256,0);

//             for(int j = i; j < n; j++) {
//                 if(hash[s[j]] == 1) break;

//                 hash[s[j]] = 1;
//                 int len = j - i + 1;

//                 maxlen = max(maxlen,len);
//             }
//         }
//         return maxlen;
//     }
// };



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int maxlen = 0;
        int left = 0;

        unordered_set<char> uniqueChars;
        for(int right = 0; right < size; right++) {
            while(uniqueChars.find(s[right]) != uniqueChars.end()) {
                uniqueChars.erase(s[left]);
                left++;
            }

            uniqueChars.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};