class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count =0;
        int multiplication = 1;

        vector<int> result;

        for(auto it:nums){
             if(0==it) zero_count+=1;
             else multiplication*=it;
        }

        for(auto it:nums){
            if(zero_count>1) result.push_back(0);
            else if(zero_count==1&&it==0) result.push_back(multiplication);
            else if(zero_count==1) result.push_back(0);
            else result.push_back(multiplication/it);

        }

        return result;


    }
};
