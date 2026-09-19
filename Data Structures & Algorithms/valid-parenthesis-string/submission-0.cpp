class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        
        for (char c : s) {
            minOpen += (c == '(') ? 1 : -1;
            maxOpen += (c == ')') ? -1 : 1;
            
            if (maxOpen < 0) return false;  // too many ')'s
            if (minOpen == -1) minOpen++;   // edge case where we counted '*' as ')' even if there wasnt any '('
        }
        return minOpen == 0;
    }
};
