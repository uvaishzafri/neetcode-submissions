class Solution {
   public:
    bool isEatable(vector<int> piles, int h, int k) {
        int timeTaken = 0;
        for (auto it : piles) {
            timeTaken += it / k;
            if (it % k) timeTaken += 1;
        }
        return timeTaken <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MAX;
        int result = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isEatable(piles, h, mid)) {
                result = min(result, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
