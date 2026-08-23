class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int curr = 1;
                    while (!q.empty()) {
                        pair<int, int> top = q.front();
                        q.pop();
                        int r[4] = {1, 0, -1, 0};
                        int c[4] = {0, 1, 0, -1};
                        for (int k = 0; k < 4; k++) {
                            int row = top.first + r[k];
                            int column = top.second + c[k];

                            if (row > -1 && row < n && column > -1 && column < m &&
                                !visited[row][column] && grid[row][column] == 1) {
                                q.push({row, column});
                                visited[row][column] = true;
                                curr += 1;
                            }
                        }
                    }
                    result = max(result, curr);
                }
            }
        }
        return result;
    }
};
