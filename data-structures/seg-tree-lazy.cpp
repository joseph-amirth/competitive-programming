template <typename T, typename F = function<T(const T&, const T&)>> class SegmentTree {
public:
    int n;
    vector<T> t, lazy;
    F f;
    SegmentTree() : n(), t(), f(), lazy() {}

    template <typename U> void build(const U& arr, int _n, F func = plus<T>()) {
        n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);

        function<void(int, int, int)> build = [&] (int i, int l, int r) {
            if (l == r) {
                t[i] = T(arr[l]);
                return;
            }

            int mid = l + (r - l) / 2;
            build(i << 1, l, mid);
            build(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(1, 0, n - 1);
    }

    void push (int x, int l, int r) {
        //lazy
    }

    template <typename U> void update(int idx, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (l == r) {
                t[i] = T(val);
                return;
            }
            push(i, l, r);
            int mid = l + (r - l) / 2;
            if (idx <= mid)
                update(i << 1, l, mid);
            else update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    template <typename U> void update(int ql, int qr, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (ql <= l and r <= qr) {
                //lazy
                return;
            }
            push(i, l, r);
            int mid = l + (r - l) / 2;
            update(i << 1, l, mid);
            update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    T query(int ql, int qr) {
        function<T(int, int, int)> query = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return T(); //identity element of f
            if (ql <= l and r <= qr)
                return t[i];
            push(i, l, r);
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};
