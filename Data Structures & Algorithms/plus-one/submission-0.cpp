class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result(n, 0);
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < n; i++) {
            int sum = digits[i] + carry;
            if (sum == 10) {
                result[i] = 0;
                carry = 1;
            } else {
                result[i] = sum;
                carry = 0;
            }
        }
        if (carry) result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
