class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

    void dfs(TreeNode* node, int& sum) {
        if (!node) return;

        dfs(node->right, sum);
        sum += node->val;
        node->val = sum;
        dfs(node->left, sum);
    }
};