class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
       // taking template from course schedule 1
        vector<vector<int>> graph(n);
        vector<int> in(n, 0);  // indegree
        vector<bool> visited(n, false);
        queue<int> q;
        vector<int> result;

        for (auto it : pre) {
            graph[it[1]].push_back(it[0]);  // pre- > current mapping
            in[it[0]] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
                result.push_back(i);
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
                    result.push_back(it);
                    visited[it] = true;
                }
            }
        }

        vector<int> empty;

        return result.size()==n?result:empty;

    }
};
