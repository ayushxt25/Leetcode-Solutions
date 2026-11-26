class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto& [c, f] : freq)
            pq.push({f, c});

        string ans;

        while (!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();
            ans.append(f, c);
        }

        return ans;
    }
};