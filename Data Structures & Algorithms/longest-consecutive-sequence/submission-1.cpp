class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int result =0;
        for(auto it:seen){
            if(seen.contains(it-1)==false){
                int curr_max= 1;
                int curr=it+1;
                while(seen.contains(curr++)){
                    curr_max+=1;
                }
                result= max(curr_max,result);
            }
        }
        return result;
    }
};
