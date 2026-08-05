class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[1005] = {0};
        int postfix[1005] = {0};
        int curr_max = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = curr_max;
            curr_max = max(curr_max, height[i]);
        }
        curr_max = 0;
        for (int i = n - 1; i > -1; i--) {
            postfix[i] = curr_max;
            curr_max = max(curr_max, height[i]);
        }

        for (int i = 0; i < n; i++) {
            if (min(prefix[i], postfix[i]) > height[i]) {
                result += (min(prefix[i], postfix[i]) - height[i]);
            }
        }
        return result;
    }
};
