class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    result += 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        int r[4] = {0, 1, 0, -1};
                        int c[4] = {1, 0, -1, 0};
                        for (int k = 0; k < 4; k++) {
                            int row = top.first + r[k];
                            int column = top.second + c[k];
                            if (row > -1 && row < n && column > -1 && column < m &&
                                grid[row][column] == '1' && !visited[row][column]) {
                                visited[row][column] = true;
                                q.push({row, column});
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};
