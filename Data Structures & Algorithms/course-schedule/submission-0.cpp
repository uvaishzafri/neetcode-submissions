class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> in(n, 0);  // indegree
        vector<bool> visited(n, false);
        queue<int> q;
        for (auto it : pre) {
            graph[it[1]].push_back(it[0]);  // pre- > current mapping
            in[it[0]] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : graph[curr]) {
                in[it] -= 1;
                if (in[it] == 0) {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }

        for (auto it : visited)
            if (it == false) return false;
        return true;
    }
};
