class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if(board[r][c]=='.') continue;
                string row = 'r' + to_string(r) + board[r][c];
                string column = 'c' + to_string(c) + board[r][c];
                string boar = 'b' + to_string(r / 3) + to_string(c/3)+board[r][c];
                //cout<<row<<" "<<column<<" "<<boar<<endl;

                if (seen.contains(row) || seen.contains(column) || seen.contains(boar))
                    return false;
                    seen.insert(row);
                    seen.insert(column);
                    seen.insert(boar);
            }
        }
        return true;
    }
};
