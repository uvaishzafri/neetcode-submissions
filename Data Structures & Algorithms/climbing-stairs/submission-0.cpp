class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(50,0);
        steps[1]=1;
        steps[2]=2;
        for(int i=3;i<50;i++){
            steps[i] = steps[i-1]+steps[i-2];
        }
        return steps[n];
    }
};
