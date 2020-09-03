struct Node {
    Node* arr[26];
    bool isEnd;
};

class Trie {
public:
    Node *root;
    Trie(): root(new Node()) {}

    void insert (const string& s) {
        Node *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                curNode->arr[ch - 'a'] = new Node();
            curNode = curNode->arr[ch - 'a'];
        }
        curNode->isEnd = true;
    }

    bool search(const string& s) {
        Node *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                return false;
            curNode = curNode->arr[ch - 'a'];
        }
        return (curNode != nullptr and curNode->isEnd);
    }

    ~Trie() {
        if (root != nullptr) {
            function<void(Node*)> dfs = [&] (Node *x) {
                for (int i = 0; i < 26; i++) {
                    if (x->arr[i])
                        dfs(x->arr[i]);
                }
                delete x;
            };
            dfs(root);
        }
    }
};
