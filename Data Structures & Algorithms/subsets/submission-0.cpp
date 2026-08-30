class Solution {
   public:
    vector<vector<int>> result;

    void processSubset(vector<int>& nums, vector<int> curr, int index, int n) {
        if (index == n) {
            result.push_back(curr);
            return;
        }
        
        processSubset(nums, curr, index + 1, n);
        curr.push_back(nums[index]);
        processSubset(nums, curr, index + 1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        processSubset(nums, curr, 0, n);
        return result;
    }
};
