struct combine {
    static int e;
    int operator()(const int& a, const int & b) const {
        return a + b;
    }
};

int combine::e = 0;

template <typename T, typename F> class SegmentTree {
public:
    int n;
    vector<T> t;
    SegmentTree() : n(), t() {}

    template <typename U> void build(const U& arr, int m) {
        n = m;
        t.resize(4 * n + 4);
        build(arr, 1, 0, n - 1);
    }

    template <typename U> void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = F()(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U> void update(int idx, U val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(int idx, U val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(idx, val, i << 1, l, mid);
        else update(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = F()(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return F::e;
        if (l >= ql and r <= qr)
            return t[i];
        int mid = l + (r - l) / 2;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return F()(x, y);
    }
};
