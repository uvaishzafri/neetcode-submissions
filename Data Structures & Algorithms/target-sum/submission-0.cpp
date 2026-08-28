class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> dp;

        dp[0]=1;
        for(auto it: nums){
            map<int,int> dp2;
            for(auto it2: dp){
                int value = it2.first;
                int count = it2.second;
                dp2[value+it] += count;
                dp2[value-it] += count;
            }
            dp=dp2;
        }

        return dp[target];
    }
};
