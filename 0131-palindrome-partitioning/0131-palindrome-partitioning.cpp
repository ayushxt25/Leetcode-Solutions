class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        vector<string> path;

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1]);
            }
        }

        backtrack(0, s, dp, path, ans);
        return ans;
    }

    void backtrack(int start, string& s, vector<vector<bool>>& dp, vector<string>& path, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp, path, ans);
                path.pop_back();
            }
        }
    }
};