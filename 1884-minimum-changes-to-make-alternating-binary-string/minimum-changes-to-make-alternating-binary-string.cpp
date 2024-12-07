// class Solution {
// public:
//     int minOperations(string s) {
//         int count  = 0;
//         for(int i = 1; i < s.size(); i++){
//             if(s[i] == s[i-1]) {
//                 s[i] = (s[i]=='0')?'1':'0';
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minOperations(string s) {
        int countPattern1 = 0, countPattern2 = 0;

        // Compare the string to two alternating patterns: "010101..." and "101010..."
        for (int i = 0; i < s.size(); i++) {
            // Compare with pattern "010101..."
            if (s[i] != (i % 2 == 0 ? '0' : '1')) {
                countPattern1++;
            }
            // Compare with pattern "101010..."
            if (s[i] != (i % 2 == 0 ? '1' : '0')) {
                countPattern2++;
            }
        }

        // The minimum operations required to make the string alternate
        return min(countPattern1, countPattern2);
    }
};
