class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> index(queries.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> result(queries.size(), -1);
        int i = 0;

        for (int id : index) {
            int q = queries[id];
            while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().second<q) pq.pop();
            if(!pq.empty()) result[id]=pq.top().first;
        }
        return result;
    }
};
