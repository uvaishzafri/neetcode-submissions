class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      vector<vector<bool>> visited(n, vector<bool> (m, false));
      int result = 0;
      queue<pair<pair<int,int>, int>> q; //row, column, time

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
            q.push({{i,j},0});
            visited[i][j]= true;
            }
        }
      }
      while(!q.empty()){
        cout<<"here";
        pair<pair<int,int>, int> orange = q.front();
        q.pop();
        result = max(result, orange.second);
        int r[4]= {1,0,-1,0};
        int c[4]= {0,1,0,-1};
        for(int i=0;i<4;i++){
            int row = orange.first.first+r[i];
            int column = orange.first.second+c[i];
            cout<<row<<" "<<column<<endl;
            cout<<(row>-1)<<" "<<(row<n)<<" "<<(column>-1)<<" "<<(column<m)<<endl;
            //<<(grid[row][column]==1)<<" "<<(visited[row][column]==false)<<endl;
            if(row>-1&&row<n&&column>-1&&column<m&&grid[row][column]==1&&visited[row][column]==false){
                visited[row][column] = true;
                grid[row][column]=2;
                cout<<"there"<<endl;
                q.push({{row,column}, orange.second+1});
            }
        }
      }

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
      }
    

      return result;
    }
};
