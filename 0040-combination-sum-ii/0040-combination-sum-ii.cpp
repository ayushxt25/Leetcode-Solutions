class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, path, ans);

        return ans;
    }

    void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            path.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, path, ans);
            path.pop_back();
        }
    }
};