class Solution {
public:
    unordered_map<int, int> freq;
    int mx = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int sum = root->val + dfs(root->left) + dfs(root->right);
        mx = max(mx, ++freq[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;
        for (auto& [sum, count] : freq) {
            if (count == mx)
                ans.push_back(sum);
        }

        return ans;
    }
};