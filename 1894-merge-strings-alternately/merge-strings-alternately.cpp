class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        string result = "";

        for(int i = 0; i < max(size1, size2); i++){
            if(i < size1){
                result.push_back(word1[i]);
            }

            if(i < size2){
                result.push_back(word2[i]);
            }
        }
        return result;
    }
};