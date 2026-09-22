class Solution {
public:
bool isPossible(int limit, int n, vector<vector<int>>& grid){
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0]=true;
        queue<pair<int,int>> visitQueue;
        visitQueue.push({0,0});
        int offset[5]={0,1,0,-1,0};
        while(!visitQueue.empty()){
            pair<int,int> element = visitQueue.front();
            int i=element.first;
            int j = element.second;
        
            if(i==n-1&&j==n-1){
                return true;
            }
            visitQueue.pop();
            for(int k=0;k<4;k++){
                int r = i+offset[k];
                int c= j+offset[k+1];
                
                if(r<n&&r>-1&&c<n&&c>-1&&visited[r][c]==false&&grid[r][c]<=limit){
                     visited[r][c]=true;
                    visitQueue.push({r,c});
                }
            }

        }
        return false;
        
}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0];
        int right = n*n;
        while(left<right){
                int mid = (right-left)/2+left;
                cout<<mid<<" ";
                if(isPossible(mid, n, grid)){
                    right = mid;
                    cout<<"possible";
                    
                }
                else{
                    left = mid+1;
                    cout<<"yumpossible";
                }
                cout<<endl;
        }
        return right;
    }
};