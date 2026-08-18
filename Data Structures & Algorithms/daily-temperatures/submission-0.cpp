class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temp[st.top()] < temp[i]) {
                int topIndex = st.top();
                st.pop();
                result[topIndex] = i - topIndex;
            }
            st.push(i);
        }
        while (!st.empty()) {
            int topIndex = st.top();
            st.pop();
            result[topIndex] = 0;
        }
        return result;
    }
};
