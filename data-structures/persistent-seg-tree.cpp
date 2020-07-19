template <typename T, T e = T()> class SegmentTree {
public:
    #define F function<T(const T&, const T&)>

    struct node {
        T val;
        node *l, *r;
        explicit node(T val) : val(val), l(nullptr), r(nullptr) {}
        node(T val, node* l, node* r): val(val), l(l), r(r) {}
    };

    int n;
    F f;
    vector<node*> root;
    node* ver;

    SegmentTree(): root(), n(), ver(), f() {}

    template <typename U> void build(const U& arr, int _n, F func = plus<T>()) {
        n = _n;
        f = func;
        root = {build(0, n - 1)};
        ver = root.back();
    }

    template <typename U> node* build(const U& arr, int l, int r) {
        if (l == r) {
            node* temp = new node(arr[l]);
            return temp;
        }

        int mid = l + (r - l) / 2;
        node* temp1 = build(arr, l, mid);
        node* temp2 = build(arr, mid + 1, r);
        return new node(f(temp1->val, temp2->val), temp1, temp2);
    }

    void update(int idx, int val) {
        root.push_back(update(idx, val, ver, 0, n - 1));
        ver = root.back();
    }

    node* update(int idx, int val, node* v, int l, int r) {
        if (l == r)
            return new node(val);

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            node* temp = update(idx, val, v->l, l, mid);
            return new node(f(temp->val, v->r->val), temp, v->r);
        } else {
            node *temp = update(idx, val, v->r, mid + 1, r);
            return new node(f(v->l->val, temp->val), v->l, temp);
        }
    }

    T query(int ql, int qr) {
        return query(ql, qr, ver, 0, n - 1);
    }

    T query(int ql, int qr, node* v, int l, int r) {
        if (ql > r or l > qr)
            return e;
        if (ql <= l and r <= qr)
            return v->val;

        int mid = l + (r - l) / 2;
        return f(query(ql, qr, v->l, l, mid), query(ql, qr, v->r, mid + 1, r));
    }
};
