class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int result = 0;
        while(l<r){
            result= max(result, min(heights[l],heights[r])*(r-l));
            if(heights[l]>heights[r]) r-=1;
            else l+=1;
        }
        return result;
    }
};
