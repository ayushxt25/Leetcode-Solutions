class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode*> ans;

        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = generate(l, i - 1);
            vector<TreeNode*> right = generate(i + 1, r);

            for (TreeNode* a : left) {
                for (TreeNode* b : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};