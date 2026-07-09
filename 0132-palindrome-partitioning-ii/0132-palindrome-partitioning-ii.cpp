class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cuts(n);
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) cuts[i] = i;

        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;
                    cuts[end] = start == 0 ? 0 : min(cuts[end], cuts[start - 1] + 1);
                }
            }
        }

        return cuts[n - 1];
    }
};