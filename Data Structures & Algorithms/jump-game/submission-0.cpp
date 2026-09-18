class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        visited[0]=1;
        for (int i = 0; i < nums.size(); i++) {
            for(int j=1;j<=nums[i];j++)
            if(i+j<n)
            visited[i+j]=1;
        }
        for(int i=0;i<n;i++) if(visited[i]==0) return false;

        return true;
    }
};
