class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; // {startIndex, height}
        int result = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();

                result = max(result, height * (i - index));

                start = index;
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();

            result = max(result, height * ((int)heights.size() - index));
        }

        return result;
    }
};