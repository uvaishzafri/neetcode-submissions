class Solution {
public:
    vector<string> result;
    void helper(string curr, int n, int open, int closed){
        if(curr.size()==n*2){
            result.push_back(curr);
            return;
        }

        if(open<n) helper(curr+'(', n, open+1, closed);
        if(closed<n&&closed<open) helper(curr+')', n, open, closed+1);
    }
    vector<string> generateParenthesis(int n) {
        int open =0, closed =0;
        string curr ="";

        helper(curr, n, open, closed);

        return result;
    }
};
