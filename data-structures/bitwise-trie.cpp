struct Node {
    Node* arr[2];
    Node() : arr() {}
};

template <int L> class Trie {
public:
    Node *root;
    Trie(): root(new Node()) {}

    void insert (const ll& x) const {
        Node *curNode = root;
        for (int i = L; i >= 0; i--) {
            bool f = x & (1ll << i);
            if (!curNode->arr[f])
                curNode->arr[f] = new Node;
            curNode = curNode->arr[f];
        }
    }

    bool search(const ll& x) const {
        Node *curNode = root;
        for (int i = L; i >= 0; i--) {
            bool f = x & (1ll << i);
            if (!curNode->arr[f])
                return false;
            curNode = curNode->arr[f];
        }
        return (curNode != nullptr);
    }
};
