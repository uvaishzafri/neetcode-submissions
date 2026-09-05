class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k%=n;

        for(int i=0;i<k;i++){
            int curr = nums[i];
            int j = (i+1)%n;
            int prev = nums[i];

            while(j!=i){
                int temp = nums[j];
                nums[j]= prev;
                prev=temp;
                j+=1;
                j%=n;
            }
            nums[i]= prev;
        }
        

    }
};