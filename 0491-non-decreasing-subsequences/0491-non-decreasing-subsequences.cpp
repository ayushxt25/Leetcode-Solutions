class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& nums, int idx) {
        if (path.size() >= 2)
            ans.push_back(path);

        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};