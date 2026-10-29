class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> mp;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }

                long long key = ((long long)dx << 32) ^ (unsigned int)dy;
                best = max(best, ++mp[key]);
            }

            ans = max(ans, best + 1);
        }

        return ans;
    }
};