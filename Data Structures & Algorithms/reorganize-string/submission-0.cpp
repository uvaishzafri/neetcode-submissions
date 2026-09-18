class Solution {
   public:
    string reorganizeString(string s) {
        string result = "";
        char last = '.';
        priority_queue<pair<int, char>> pq;
        vector<int> cnt(26);
        for (auto it : s) cnt[it - 'a'] += 1;
        for(int i=0;i<26;i++) if(cnt[i]>0)pq.push({cnt[i], i+'a'});
        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            pq.pop();
            cout<<top.first<<" "<<top.second<<endl;
            if (top.second != last) {
                last = top.second;
                result += last;
                if (top.first > 1) pq.push({top.first - 1, last});
            } else {
                if (!pq.empty()) {
                    pair<int, char> secontTop = pq.top();
                    pq.pop();
                    last = secontTop.second;
                    result += last;
                    if (secontTop.first > 1) pq.push({secontTop.first - 1, last});
                    pq.push(top);
                }
                else return "";
            }
        }
        if(pq.empty()) return result;
        return "";
    }
};