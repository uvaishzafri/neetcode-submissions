class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0 ;
        for(auto it:tasks){
            freq[it-'A']+=1;
            maxFreq=max(maxFreq, freq[it-'A']);
        }
        int maxCount= count(freq.begin(), freq.end(), maxFreq);
        return max((int)tasks.size(), (maxFreq-1)*(n+1)+maxCount);

    }
};
