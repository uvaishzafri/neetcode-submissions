class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = n * m - 1;

        cout << n << " " << m << endl;

        while (l <= r) {
            int mid = (l + r) / 2;
            int value = matrix[mid / m][mid % m];
            if (value == target) return true;
            if (value > target)
                r = mid-1;
            else
                l = mid+1;

            cout << mid << " " << value << " " << mid / m << " " << (mid % m)
                 << " "<< matrix[mid / m][mid % m] << endl;
        }
        return false;
    }
};
