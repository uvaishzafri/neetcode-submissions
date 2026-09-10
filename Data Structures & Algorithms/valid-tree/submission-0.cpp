class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // idea is just to check for loops, while trying not to visit your immediate parent and
        // whole graph should be traversable from one node

        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        queue<pair<int, int>> q;  // curr, parent

        q.push({0, -1});
        visited[0] = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it: graph[curr]){
                if(it!=parent){
                    if(visited[it]==true) return false;
                    visited[it]= true;
                    q.push({it, curr});
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (visited[i] == false) return false;
        return true;
    }
};
