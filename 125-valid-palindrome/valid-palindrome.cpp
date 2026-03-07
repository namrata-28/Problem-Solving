class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {

            if (!((s[start] >= '0' && s[start] <= '9') || 
                  (s[start] >= 'A' && s[start] <= 'Z') || 
                  (s[start] >= 'a' && s[start] <= 'z'))) {
                start++;
                continue;
            }

            if (!((s[end] >= '0' && s[end] <= '9') || 
                  (s[end] >= 'A' && s[end] <= 'Z') || 
                  (s[end] >= 'a' && s[end] <= 'z'))) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }

        return true;
    }
};