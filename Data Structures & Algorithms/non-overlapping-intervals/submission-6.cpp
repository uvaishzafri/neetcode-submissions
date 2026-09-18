class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prev = 0;
        int result = 0;
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[prev][1]) {
                result += 1;

            } else {
                prev =i;
            }

           
        }
        return result;
    }
};
