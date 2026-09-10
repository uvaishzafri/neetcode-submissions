class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][m - 1] == 'O') q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[n - 1][j] == 'O') q.push({n - 1, j});
        }

        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};

        //cout<<q.size();

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            board[r][c] = 'Y';
            //cout<<r<<" "<<c<<endl;

            q.pop();
            for (int k = 0; k < 4; k++) {
                int row = r + x[k];
                int col = c + y[k];
                if (row < n && row > -1 && col > -1 && col < m && board[row][col] == 'O') {
                    board[row][col] = 'Y';
                    q.push({row, col});
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }
};
