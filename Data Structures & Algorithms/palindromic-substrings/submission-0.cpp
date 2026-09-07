class Solution {
   public:
    int countSubstrings(string s) {
        // taking the code from longest palindrome substring
        int n = s.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l > -1 && r < n) {
                if (s[l] == s[r]) {
                    result += 1;
                    l--;
                    r++;

                } else
                    break;
            }
            l = i, r = i + 1;
            while (l > -1 && r < n) {
                if (s[l] == s[r]) {
                    result += 1;
                    l--;
                    r++;

                } else
                    break;
            }
        }
        return result;
    }
};
