class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>> paths(n, vector<int>(m, 0));
        paths[0][0]=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i==0&&j==0) continue;
                int top = j == 0 ? 0 : paths[i][j - 1];
                int left = i == 0 ? 0 : paths[i - 1][j];
                if(grid[i][j]==0)
                paths[i][j] = top + left;
                else paths[i][j]=0;

                cout<<paths[i][j]<<" ";
            }
            cout<<endl;
        }
        if (n == 1 || m == 1) return 1;
        return paths[n - 1][m - 1];
    }
};