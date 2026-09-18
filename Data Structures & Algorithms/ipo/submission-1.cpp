class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n);

        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return capital[a] < capital[b]; });

        priority_queue<int> pq;

       
        int i = 0;
        for (int r = 0; r < k; r++) {
            while (i < n && capital[idx[i]] <= w) pq.push(profits[idx[i++]]);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};