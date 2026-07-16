class Solution {
private:
    TreeNode* prev = nullptr;
    int currCount = 0, maxCount = 0;
    vector<int> ans;

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (prev && prev->val == node->val) currCount++;
        else currCount = 1;

        if (currCount > maxCount) {
            maxCount = currCount;
            ans.clear();
            ans.push_back(node->val);
        } else if (currCount == maxCount) {
            ans.push_back(node->val);
        }

        prev = node;

        inorder(node->right);
    }
};