class Solution {
private:
    unordered_map<char, char> mappings;

public:
    Solution() {
        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';
    }
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (mappings.find(c) == mappings.end()) {  
                stk.push(c);
            } else {
                // Check if the stack is empty or the top of the stack does not match
                if (stk.empty() || mappings[c] != stk.top()) {
                    return false;
                }
                // Pop the top of the stack as it's a valid match
                stk.pop();
            }
        }
        return stk.empty();
    }
};