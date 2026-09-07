class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";

        for(int i=0;i<n;i++){
            int l=i, r=i;
            while(l>-1&&r<n){
                if(s[l]==s[r]){
                  
                    if((r-l+1)>result.size()){
                        result = s.substr(l, r-l+1);
                    }
                      l--;
                    r++;

                }
                else break;
            }
             l=i, r=i+1;
              while(l>-1&&r<n){
                if(s[l]==s[r]){
                   
                    if((r-l+1)>result.size()){
                        result = s.substr(l, r-l+1);
                    }
                      l--;
                    r++;

                }
                else break;
            }
        }
        return result;
    }
};
