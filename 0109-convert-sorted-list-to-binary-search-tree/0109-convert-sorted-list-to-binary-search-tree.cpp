class Solution {
public:
    ListNode* head;

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;

        TreeNode* left = build(l, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        root->left = left;
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;

        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        return build(0, n - 1);
    }
};