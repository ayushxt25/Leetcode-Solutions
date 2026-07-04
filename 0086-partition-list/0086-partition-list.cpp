class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode *b = &before, *a = &after;

        while (head) {
            if (head->val < x) {
                b->next = head;
                b = b->next;
            } else {
                a->next = head;
                a = a->next;
            }
            head = head->next;
        }

        a->next = nullptr;
        b->next = after.next;

        return before.next;
    }
};