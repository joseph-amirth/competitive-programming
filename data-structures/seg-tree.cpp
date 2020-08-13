template <typename T> class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U> void build(const U& arr, int _n, T _e, F _f) {
        n = _n;
        t.resize(4 * n + 4);
        e = _e;
        f = _f;
        build(arr, 1, 0, n - 1);
    }

    template <typename U> void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U> void update(const int& idx, const U& val) {
        update(idx, val, 1, 0, n - 1);
    }

    template <typename U> void update(const int& idx, const U& val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(idx, val, i << 1, l, mid);
        else update(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }

    T query(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        int mid = (l + r) >> 1;
        T x = query(ql, qr, i << 1, l, mid), y = query(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};
