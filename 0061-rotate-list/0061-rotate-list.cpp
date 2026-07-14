class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0) return head;

        tail->next = head;

        int steps = n - k;
        while (steps--) tail = tail->next;

        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};