class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        int offset[5] = {0, 1, 0, -1, 0};
        visited[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int r = x + offset[k];
            int c = y + offset[k + 1];
            if (r >= 0 && c >= 0 && r < n && c < m && 
                grid[r][c] >= grid[x][y] && !visited[r][c]) {
                visited[r][c] = true;
                dfs(r, c, n, m, grid, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return {};
        int m = grid[0].size();

        vector<vector<bool>> visitedByPacific(n, vector<bool>(m, false));
        vector<vector<bool>> visitedByAtlantic(n, vector<bool>(m, false));
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            dfs(i, 0, n, m, grid, visitedByPacific);
            dfs(i, m - 1, n, m, grid, visitedByAtlantic);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, n, m, grid, visitedByPacific);
            dfs(n - 1, j, n, m, grid, visitedByAtlantic);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visitedByPacific[i][j] && visitedByAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};