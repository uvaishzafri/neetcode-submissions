class MyCalendar {
private:
    set<pair<int, int>> events;

public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        if (startTime >= endTime) {
            return false;
        }

        auto next = events.lower_bound({startTime, startTime});
        if (next != events.end() && next->first < endTime) {
            return false;
        }
        if (next != events.begin()) {
            auto prev = std::prev(next);
            if (prev->second > startTime) {
                return false;
            }
        }

        events.insert({startTime, endTime});
        return true;
    }
};