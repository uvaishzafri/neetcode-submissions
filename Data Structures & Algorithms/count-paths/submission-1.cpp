class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(n, vector<int>(m));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int top = j == 1 ? 1 : paths[i][j - 1];
                int left = i == 1 ? 1 : paths[i - 1][j];
                paths[i][j] = top + left;
            }
        }
        if(n==1||m==1) return 1;
        return paths[n - 1][m - 1];
    }
};
