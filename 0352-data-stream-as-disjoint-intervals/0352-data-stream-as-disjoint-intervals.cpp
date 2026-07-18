class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}
    
    void addNum(int value) {
        int start = value, end = value;

        auto next = intervals.upper_bound(value);

        if (next != intervals.begin()) {
            auto prev = std::prev(next);
            if (prev->second >= value) return;
            if (prev->second + 1 == value) {
                start = prev->first;
                intervals.erase(prev);
            }
        }

        if (next != intervals.end() && next->first == value + 1) {
            end = next->second;
            intervals.erase(next);
        }

        intervals[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto& [start, end] : intervals) {
            ans.push_back({start, end});
        }

        return ans;
    }
};