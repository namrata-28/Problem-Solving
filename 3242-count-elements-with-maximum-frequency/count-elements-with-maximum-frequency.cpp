class Solution {
public:
    // Leetcode editorial optimised 1 pass
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0, elemCount = 0;
        unordered_map<int,int> freqMap;
        for(int num : nums) {
            freqMap[num]++;
            int freq = freqMap[num];

            if(freq > maxFreq) {
                maxFreq = freq;
                elemCount = freq;
            } else if(freq == maxFreq) {
                elemCount += freq;
            }
        }
        return elemCount;
    }
};

// My code 

// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         int maxFreq = INT_MIN;
//         unordered_map<int,int> freqMap;

//         for(int num : nums) {
//             freqMap[num] += 1;
//             maxFreq = max(maxFreq,freqMap[num]);
//         }

//         int elemCount = 0;
//         for(auto it : freqMap) {
//             if(it.second == maxFreq) {
//                 elemCount += it.second;
//             }
//         }
//         return elemCount;
//     }
// };