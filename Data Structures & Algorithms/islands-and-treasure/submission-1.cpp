class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;  // i,j and distance

        // calculate distance from 0 to INT_MAX, avoiding -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            int x[4] = {1, 0, -1, 0};
            int y[4] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int row = r + x[k];
                int col = c + y[k];
                if (row < n && row > -1 && col > -1 && col < m && grid[row][col] > 1 + grid[r][c]) {
                    grid[row][col] = grid[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
    }
};
