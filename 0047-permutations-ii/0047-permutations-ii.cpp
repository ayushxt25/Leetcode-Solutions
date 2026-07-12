class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(nums, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(nums);

        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }
    }
};