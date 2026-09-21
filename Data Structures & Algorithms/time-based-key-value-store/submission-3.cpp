class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mapper;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mapper[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        auto& values = mapper[key];

        auto it = upper_bound(
            values.begin(), values.end(),
            timestamp,
            [](int t, const pair<string, int>& p) {
                return t < p.second;
            }
        );

        if (it == values.begin())
            return "";

        --it;
        return it->first;
    }
};