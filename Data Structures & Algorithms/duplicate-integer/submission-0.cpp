class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         map<int,int> hash_map;
         for(auto iterator: nums){
            hash_map[iterator]+=1;
         }
         bool has_duplicate = false;   
         for(auto iterator:hash_map){
            if(iterator.second>1){
                has_duplicate = true;
            }
         }
         return has_duplicate;
    }
};
