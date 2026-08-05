class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frequencyCounter;
        for(auto it:nums){
            frequencyCounter[it]++;
        }
        vector<pair<int,int>> frequencyPair;
        for(auto it: frequencyCounter){
            frequencyPair.push_back({it.first, it.second});
        }
        sort(frequencyPair.begin(), frequencyPair.end(), [](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
        vector<int> result;
       
        for(int i=0;i<k;i++){
            result.push_back(frequencyPair[i].first);
        }
        return result;
    }
};
