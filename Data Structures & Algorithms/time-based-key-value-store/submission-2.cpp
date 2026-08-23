class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> mapper;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mapper[key].push_back({value, timestamp}); }

    string get(string key, int timestamp) {
        vector<pair<string, int>>& values = mapper[key];
        int n = values.size();
        if (n == 0) return "";
        int l = 0, r = n - 1;
        string result = "";
        while (l <= r) {
            int mid = (l + r) / 2;
            if (values[mid].second <= timestamp) result = values[mid].first;
            if (values[mid].second == timestamp) return result;
            if (values[mid].second < timestamp)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return result;
    }
};
