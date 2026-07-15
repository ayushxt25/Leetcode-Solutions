class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(1, n, k, path, ans);
        return ans;
    }

    void backtrack(int start, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(i + 1, n, k, path, ans);
            path.pop_back();
        }
    }
};