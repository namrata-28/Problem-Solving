class Solution {
public:
    void backtrack(vector<string> &ans, int n, int oc, int cc, string s){
        if(oc == n && cc == n){
            ans.push_back(s);
            return;
        }

        if(oc<n){
            backtrack(ans,n,oc+1,cc,s+"(");
        }

        if(cc<oc){
            backtrack(ans,n,oc,cc+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0, cc = 0;
        backtrack(ans,n,oc,cc,"");
        return ans;
    }
};