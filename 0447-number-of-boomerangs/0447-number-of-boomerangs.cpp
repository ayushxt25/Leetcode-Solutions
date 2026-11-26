class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;

        for (auto& a : points) {
            unordered_map<int, int> freq;

            for (auto& b : points) {
                int dx = a[0] - b[0];
                int dy = a[1] - b[1];
                int d = dx * dx + dy * dy;
                freq[d]++;
            }

            for (auto& [d, count] : freq)
                ans += count * (count - 1);
        }

        return ans;
    }
};