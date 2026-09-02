class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long required_sum = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];
                    if (sum == required_sum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < right && nums[left] == nums[left + 1]) left += 1;
                        while (right - 1 > left && nums[right] == nums[right - 1]) right -= 1;
                        left += 1;
                        right -= 1;
                    } else if (sum < required_sum)
                        left += 1;
                    else
                        right -= 1;
                }
            }
        }
        return result;
    }
};