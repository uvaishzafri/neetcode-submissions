class Solution {
public:
int robber(vector<int>&nums, int l, int r){
    int n= nums.size();
     vector<int> theft_amount(n, 0);
        theft_amount[l] = nums[l];
        if (r-l > 1) theft_amount[l+1] = nums[l+1];
        for (int i = l; i < r; i++) {
            if (i + 2 < r) theft_amount[i + 2] = nums[i + 2] + theft_amount[i];
            if (i + 1 < r) theft_amount[i + 1] = max(theft_amount[i + 1], theft_amount[i]);
        }

        return max(theft_amount[r - 1], (r-l) > 1 ? theft_amount[r - 2] : 0);

}
    int rob(vector<int>& nums) {
         int n = nums.size();
         if(n==1) return nums[0];

        return max(robber(nums,0,n-1), robber(nums,1,n));


        //code from house robber-1 
       
    }
};
