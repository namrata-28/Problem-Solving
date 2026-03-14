class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n1 = p.size();
        int n2 = s.size();

        if(n1 > n2) return ans;

        vector<int> f1(26,0);
        vector<int> f2(26,0);

        for(int i = 0; i < n1; i++){
            f1[p[i]-'a']++;
            f2[s[i]-'a']++;
        }

        if(f1 == f2) ans.push_back(0);

        for(int i = n1; i < n2; i++){
            f2[s[i]-'a']++;
            f2[s[i-n1]-'a']--;

            if(f1 == f2) ans.push_back(i-n1+1);
        }

        return ans;
    }
};