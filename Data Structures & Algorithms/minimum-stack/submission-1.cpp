class MinStack {
   public:
    stack<pair<int, int>> minStack;
    MinStack() {}

    void push(int val) {
        if (minStack.empty()) {
            minStack.push({val, val});
        } else {
            int currentMin = minStack.top().second;
            minStack.push({val, min(val, currentMin)});
        }
    }

    void pop() { minStack.pop(); }

    int top() { return minStack.top().first; }

    int getMin() { return minStack.top().second; }
};