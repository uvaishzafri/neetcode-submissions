class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mapper;
        for(auto it: nums){
            mapper[it]++;
            if(mapper[it]>1) return true;
        }
        return false;
    }
};