class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> min_cost(n+1, INT_MAX);
        min_cost[1] = 0;
        min_cost[0] = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n) {
                min_cost[i + 1] = min(min_cost[i + 1], cost[i] + min_cost[i]);
            }
            if (i + 2 <= n) {
                min_cost[i + 2] = min(min_cost[i + 2], cost[i] + min_cost[i]);
            }
            cout<<min_cost[i]<<endl;
        }
        
        
        return min_cost[n];
    }
};
