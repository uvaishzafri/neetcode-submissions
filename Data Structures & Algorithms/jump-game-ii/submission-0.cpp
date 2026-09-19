class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, curr_end =0, farthest = 0;
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest, curr_end+nums[i]);
            if(i==curr_end){
                jumps+=1;
                curr_end = farthest;
            }
        }
        return jumps;
    }
};
