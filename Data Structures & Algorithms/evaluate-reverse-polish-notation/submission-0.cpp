class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int result = 0;

                if (it == "+") result = first + second;
                if (it == "-") result = first - second;
                if (it == "*") result = first * second;
                if (it == "/") result = first / second;

                st.push(result);

            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
