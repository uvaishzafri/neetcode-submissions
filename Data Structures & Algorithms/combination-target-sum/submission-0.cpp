class Solution {
public:
    void helper(int index, int target, vector<int>&nums , vector<int>&current, vector<vector<int>>& ans )
    {
        if(target==0)
        {
            ans.push_back(current );
            return ;
        }
        if(target<0 || index==nums.size())
        {
            return ;
        }
        if(nums[index]<=target)
        
        {
            current.push_back(nums[index]);
            helper(index,target-nums[index],nums,current,ans);
            current.pop_back();
        }
        helper(index+1,target,nums,current,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
      vector<vector<int>>ans;
      vector<int>current;
      helper(0,target,nums,current,ans);
      return ans;
        
    }
};
