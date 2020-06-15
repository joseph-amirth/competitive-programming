class Trie {
public:
    struct TrieNode {
        TrieNode* arr[26];
        bool isEnd;
        TrieNode() : arr{}, isEnd() {}
    };
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert (const string& s) const {
        TrieNode *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                curNode->arr[ch - 'a'] = new TrieNode();
            curNode = curNode->arr[ch - 'a'];
        }
        curNode->isEnd = true;
    }

    bool search(const string& s) const {
        TrieNode *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                return false;
            curNode = curNode->arr[ch - 'a'];
        }
        return (curNode != nullptr and curNode->isEnd);
    }
};
