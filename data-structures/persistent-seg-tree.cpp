template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    struct Node {
        T val;
        Node *l, *r;
        explicit Node(T val) : val(val), l(nullptr), r(nullptr) {}
        Node(T val, Node* l, Node* r): val(val), l(l), r(r) {}
    };

    int n;
    vector<Node*> root;
    Node* curVer;
    T e;
    F f;
    SegmentTree(): root(), n(), curVer(), e(), f() {}

    void changeVer(int k) {
        assert(k >= 1 and k <= root.size());
        curVer = root[k - 1];
    }

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), e(e), f(f) {
        root.push_back(build(arr, 0, n - 1));
        curVer = root.back();
    }

    template <typename U>
    Node* build(const U& arr, int l, int r) {
        if (l == r) {
            Node* temp = new Node(T(arr[l]));
            return temp;
        }

        int mid = (l + r) >> 1;
        Node* temp1 = build(arr, l, mid);
        Node* temp2 = build(arr, mid + 1, r);
        return new Node(f(temp1->val, temp2->val), temp1, temp2);
    }

    template <typename U>
    void update(int idx, U val) {
        root.push_back(updateHelper(idx, val, curVer, 0, n - 1));
        curVer = root.back();
    }

    template <typename U>
    Node* updateHelper(int idx, U val, Node *v, int l, int r) {
        if (l == r)
            return new Node(T(val));

        int mid = (l + r) >> 1;
        if (idx <= mid) {
            Node *temp = updateHelper(idx, val, v->l, l, mid);
            return new Node(f(temp->val, v->r->val), temp, v->r);
        } else {
            Node *temp = updateHelper(idx, val, v->r, mid + 1, r);
            return new Node(f(v->l->val, temp->val), v->l, temp);
        }
    }

    T query(int ql, int qr) {
        return queryHelper(ql, qr, curVer, 0, n - 1);
    }

    T queryHelper(int ql, int qr, Node *v, int l, int r) {
        if (ql > r or l > qr)
            return e;
        if (ql <= l and r <= qr)
            return v->val;

        int mid = (l + r) >> 1;
        return f(queryHelper(ql, qr, v->l, l, mid), queryHelper(ql, qr, v->r, mid + 1, r));
    }
};
