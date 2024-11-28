class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> freq;

        for(int num : arr){
            freq[num]++;
        }

        unordered_set<int> freqSet;
        for(auto[key,value] : freq) {
            if(freqSet.find(value)!= freqSet.end()){
                return false;
            }
            freqSet.insert(value);
        }
        return true;
    }
};