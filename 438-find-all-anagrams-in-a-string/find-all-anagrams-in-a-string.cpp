class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        if (ns < np) return {};

        unordered_map<char, int> pCount;
        unordered_map<char, int> sCount;

        for (char ch : p) {
            if (pCount.count(ch))
                pCount[ch]++;
            else
                pCount[ch] = 1;
        }

        vector<int> output;

        for (int i = 0; i < ns; i++) {

            char ch = s[i];
            if (sCount.count(ch))
                sCount[ch]++;
            else
                sCount[ch] = 1;

            if (i >= np) {
                ch = s[i - np];
                if (sCount[ch] == 1)
                    sCount.erase(ch);
                else
                    sCount[ch]--;
            }

            if (pCount == sCount)
                output.push_back(i - np + 1);
        }

        return output;
    }
};