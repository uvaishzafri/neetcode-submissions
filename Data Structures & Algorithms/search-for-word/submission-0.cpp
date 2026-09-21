class Solution {
public:

bool wordsearch(int row,int col, int ind,vector<vector<char>> & board,string word){
    int m = board.size();
        int n =  board[0].size();

        // checking outerbounds
        if(row <0 || col <0 || row >= m ||  col >= n){
            return false;
        }

        // if the char si not there in the board
         if (board[row][col] != word[ind]){
            return false;
         }
         // base condition
         if(ind == word.size()-1){
            return true;
        
         }

         // if hhum current cell ke character ko store krege 
         char ch = board[row][col];
         // mark krege visited
         board[row][col]='#';

         // try all foour paths
         int dr[]= { +1,0,0,-1};
         int dc[]= { 0,-1,+1,0};
          // for loop for trying every posible dirce
          for(int k = 0 ;  k< 4;k++){
            int nextrow = row + dr[k];
            int nextcol = col + dc[k];
             if (wordsearch(nextrow,nextcol,ind + 1 , board , word))
             return true;

          }
          board[row][col] = ch;
          return false;


}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n =  board[0].size();

        for(int i = 0; i< m ;i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                   if(wordsearch(i,j,0,board,word))
                    return true;
                }


            }
        }
        return false;

      
        
    }
};