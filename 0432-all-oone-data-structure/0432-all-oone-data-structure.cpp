class AllOne {
private:
    struct Node {
        int cnt;
        unordered_set<string> keys;
        Node* prev;
        Node* next;

        Node(int c) : cnt(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;

    void insertAfter(Node* node, Node* newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (!mp.count(key)) {
            if (head->next == tail || head->next->cnt != 1) {
                insertAfter(head, new Node(1));
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        } else {
            Node* node = mp[key];
            int newCnt = node->cnt + 1;

            if (node->next == tail || node->next->cnt != newCnt) {
                insertAfter(node, new Node(newCnt));
            }

            node->next->keys.insert(key);
            mp[key] = node->next;
            node->keys.erase(key);

            if (node->keys.empty()) removeNode(node);
        }
    }

    void dec(string key) {
        Node* node = mp[key];

        if (node->cnt == 1) {
            mp.erase(key);
        } else {
            int newCnt = node->cnt - 1;

            if (node->prev == head || node->prev->cnt != newCnt) {
                insertAfter(node->prev, new Node(newCnt));
            }

            node->prev->keys.insert(key);
            mp[key] = node->prev;
        }

        node->keys.erase(key);

        if (node->keys.empty()) removeNode(node);
    }

    string getMaxKey() {
        return tail->prev == head ? "" : *tail->prev->keys.begin();
    }

    string getMinKey() {
        return head->next == tail ? "" : *head->next->keys.begin();
    }
};