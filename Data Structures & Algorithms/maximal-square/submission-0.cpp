class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    int curr = 1;

                    while((i+curr)<n&&(j+curr)<m){
                        bool valid=  true;
                        for(int k=0;k<curr;k++){
                            if(matrix[i+k][j+curr]!='1') valid=false;
                            if(matrix[i+curr][j+k]!='1') valid=false;

                        }
                        if(valid&&matrix[i+curr][j+curr]=='1')
                        curr+=1;
                        else break;
                    }

                    result = max(result, curr);
                }
            }
        }


        return result*result;
    }
};