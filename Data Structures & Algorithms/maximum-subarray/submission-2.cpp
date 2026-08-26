class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int j = 1;
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int n = nums.size();

        while (j < n) {
            curr_sum += nums[j];
             cout<<curr_sum<<" ";
            if (curr_sum < nums[j]) {
                curr_sum = nums[j];
            }
            max_sum = max(curr_sum, max_sum);
            j += 1;
           // cout<<curr_sum<<endl;
        
        }
        return max_sum;
    };
};

