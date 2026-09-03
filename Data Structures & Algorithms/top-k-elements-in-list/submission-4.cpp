class Solution {
public:
struct cmp{


    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        map<int,int> mapper;
        for(auto it:nums){
            mapper[it]+=1;
        }
        for(auto it:mapper){
            pq.push({it});
            if(pq.size()>k) pq.pop();
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
