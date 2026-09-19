class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for(auto it:nums) {nums[abs(it)-1]=-nums[abs(it)-1]; if(nums[abs(it)-1]>0) return abs(it); }
        return 0;
    }
};