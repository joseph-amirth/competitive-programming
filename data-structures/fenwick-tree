template <typename T, typename F = function<T(const T&, const T&)>> class FenwickTree {
public:
    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    explicit FenwickTree(int _n, F func = plus<T>()): n(_n + 1), bit(_n + 1, 0), f(move(func)) {}

    void add(int i, int val) {
        while (i < n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        int ans = 0;
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};
