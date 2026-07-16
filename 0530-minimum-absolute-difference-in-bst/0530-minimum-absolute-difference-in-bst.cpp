class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, ans);
        return ans;
    }

    void inorder(TreeNode* node, TreeNode*& prev, int& ans) {
        if (!node) return;

        inorder(node->left, prev, ans);

        if (prev) ans = min(ans, node->val - prev->val);
        prev = node;

        inorder(node->right, prev, ans);
    }
};