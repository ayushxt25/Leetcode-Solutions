class Solution {
    int m, n, total;
    unordered_map<int, int> mp;
    mt19937 rng;

public:
    Solution(int m, int n) : m(m), n(n), total(m * n), rng(random_device{}()) {}

    vector<int> flip() {
        uniform_int_distribution<int> dist(0, total - 1);
        int r = dist(rng);

        int x = mp.count(r) ? mp[r] : r;

        total--;

        mp[r] = mp.count(total) ? mp[total] : total;
        mp.erase(total);

        return {x / n, x % n};
    }

    void reset() {
        mp.clear();
        total = m * n;
    }
};