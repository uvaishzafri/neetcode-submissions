class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(auto it: points){
            int distance = it[0]*it[0]+ it[1]*it[1];
            pq.push({distance, {it[0], it[1]}});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> result;
        cout<<pq.size();
        while(pq.size()){
            cout<<pq.top().second[0]<<" "<<pq.top().second[1]<<endl;
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
