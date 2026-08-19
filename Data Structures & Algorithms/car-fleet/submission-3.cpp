class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        set<float> timeTaken;
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({speed[i], position[i]});
        }
        sort(cars.begin(), cars.end(),
             [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        float last = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            float time_taken = float(target - cars[i].second) / cars[i].first;
            cout<<time_taken<<endl;
            if (time_taken > last) {
                timeTaken.insert(time_taken);
                last = time_taken;
            }
        }
        return timeTaken.size();
    }
};
