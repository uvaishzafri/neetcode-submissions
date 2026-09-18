class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> q;
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<tasks.size();i++){
            q.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(q.begin(), q.end());

        int curr_time = q[0][0];
        int ind = 0;
        while(ind<q.size()||!pq.empty()){
            if(pq.empty()&&curr_time<q[ind][0]){
                curr_time = q[ind][0];
            }

            while(ind<q.size()&&q[ind][0]<=curr_time){
                pq.push({q[ind][1], q[ind][2]});
                ind+=1;
            }
            curr_time+=pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

      
    }
};