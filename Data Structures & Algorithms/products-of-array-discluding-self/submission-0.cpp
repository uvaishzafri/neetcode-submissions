class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prefixMultiplication[1005], suffixMultiplication[1005];
        int currValue = 1;
        for(int i=0;i<n;i++){
            currValue*=nums[i];
            prefixMultiplication[i]=currValue;
        }
        
        currValue = 1;
        for(int i= n-1;i>-1;i--){
            currValue*=nums[i];
            suffixMultiplication[i]=currValue;
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            currValue = 1;
            if(i>0) currValue*=prefixMultiplication[i-1];
            if(i<n-1) currValue*=suffixMultiplication[i+1];
            result.push_back(currValue);
        }
        return result;
    }
};
