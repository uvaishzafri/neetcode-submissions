class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> theft_amount(n, 0);
        theft_amount[0] = nums[0];
        if (n > 1) theft_amount[1] = nums[1];
        for (int i = 0; i < n; i++) {
            if (i + 2 < n) theft_amount[i + 2] = nums[i + 2] + theft_amount[i];
            if (i + 1 < n) theft_amount[i + 1] = max(theft_amount[i + 1], theft_amount[i]);
        }

        return max(theft_amount[n - 1], n > 1 ? theft_amount[n - 2] : 0);
    }
};
