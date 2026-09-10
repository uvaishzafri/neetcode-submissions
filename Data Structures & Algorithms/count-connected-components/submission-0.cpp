class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int result = 0;
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                result+=1;
                queue<int> q;
                q.push(i);
                visited[i]= true;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(auto it: graph[curr]){
                        if(visited[it]==false){
                            visited[it]=true;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return result;

    }
};
