class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = ((n+1)*(n))/2;
        for(auto it:nums){
            expected_sum-=it;
        }
        return expected_sum;
    }
};
