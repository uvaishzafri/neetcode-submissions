class Solution {
public:
    int findIndex(vector<int> nums, int n){
            int low = 0, high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid]>=nums[0]) low=mid+1;
                else high=mid-1;
            }
            return low;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1&&nums[0]==target) return 0;
        if(n==1&&nums[0]!=target) return -1;
        
        int low=0, high = n-1;
        int index = findIndex(nums,n);
        if(nums[0]<=target) high=index-1;
        else low=index;
        cout<<index;
        cout<<low<<" "<<high;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low = mid+1;
        }

        return -1;
        
    }
};
