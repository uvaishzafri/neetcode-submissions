class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string result = "";
        for(int i=0;i<min(strs[0].size(), strs.back().size());i++){
            if(strs[0][i]==strs.back()[i]) result+=strs[0][i];
            else break;
        }
        return result;
    }
};