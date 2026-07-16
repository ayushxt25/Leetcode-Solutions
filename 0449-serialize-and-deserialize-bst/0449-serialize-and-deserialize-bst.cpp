class Codec {
public:
    string serialize(TreeNode* root) {
        string data;
        preorder(root, data);
        return data;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i, INT_MIN, INT_MAX);
    }

private:
    void preorder(TreeNode* node, string& data) {
        if (!node) return;
        data += to_string(node->val) + ",";
        preorder(node->left, data);
        preorder(node->right, data);
    }

    TreeNode* build(string& data, int& i, int low, int high) {
        if (i >= data.size()) return nullptr;

        int j = i;
        while (j < data.size() && data[j] != ',') j++;

        int val = stoi(data.substr(i, j - i));
        if (val < low || val > high) return nullptr;

        i = j + 1;
        TreeNode* root = new TreeNode(val);
        root->left = build(data, i, low, val);
        root->right = build(data, i, val, high);

        return root;
    }
};