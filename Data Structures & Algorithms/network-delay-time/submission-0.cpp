class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> distance(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        distance[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();

            for (auto [v, w] : adj[u]) {
                if (distance[v] > dist_u + w) {
                    distance[v] = dist_u + w;
                    pq.push({distance[v], v});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            result = max(result, distance[i]);
        }

        return result;
    }
};
