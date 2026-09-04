class Solution {
   public:
    bool isPalindrome(string s) {
        string alphaString = "";
        for (auto it : s) {
            if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9')) {
                if (it >= 'A' && it <= 'Z') it += 32;
                alphaString += it;
            }
        }
        string reverseString = alphaString;
        cout << alphaString << endl;
        reverse(reverseString.begin(), reverseString.end());
        return reverseString == alphaString;
    }
};
