class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString;
                while (st.top() != '[') {
                    decodedString.push_back(st.top());
                    st.pop();
                }
                st.pop();

                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k += (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }

                reverse(decodedString.begin(), decodedString.end());

                while (k-- > 0) {
                    for (char c : decodedString) {
                        st.push(c);
                    }
                }
            } else {
                st.push(s[i]);
            }
        }

        string result;
        result.reserve(st.size());
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};