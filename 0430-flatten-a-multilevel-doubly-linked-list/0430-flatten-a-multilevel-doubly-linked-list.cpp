class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* child = curr->child;
                Node* nextNode = curr->next;

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;

                Node* tail = child;
                while (tail->next) tail = tail->next;

                tail->next = nextNode;
                if (nextNode) nextNode->prev = tail;
            }

            curr = curr->next;
        }

        return head;
    }
};