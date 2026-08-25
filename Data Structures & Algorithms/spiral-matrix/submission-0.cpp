class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n= matrix.size();
        int m= matrix[0].size();

        int r[4]= {0,1,0,-1};
        int c[4]= {1,0,-1,0};
        int curr_direction =0;

        vector<int> result;

        //will mark cell as -105 for visited

        int i=0, j=-1;
        int visited = 0; //number of cells visited

        while(visited<n*m){
            int row = i+r[curr_direction];
            int column = j+c[curr_direction];
            if(row>-1&&row<n&&column>-1&&column<m&& matrix[row][column]!=-105){
                result.push_back(matrix[row][column]);
                matrix[row][column] =-105;
                i=row;
                j=column;
            }
            else{
                curr_direction+=1;
                curr_direction%=4;
                continue;
            }
            
            visited+=1;
        }
        return result;
    }
};
