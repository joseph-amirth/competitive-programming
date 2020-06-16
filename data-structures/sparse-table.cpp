template <typename T, bool I = true, typename F = function<T(const T&, const T&)>> class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    vector<int> log;
    F f;

    SparseTable(): n(), mat(), log(), f() {}
    template <typename U> void build(const U& arr, int _n, F func) {
        n = _n;
        mat.resize((int)log2(n) + 1);
        f = func;

        if (I) {
            log.resize(n + 1);
            log[1] = 0;
            for (int i = 2; i <= n; i++) {
                log[i] = 1 + log[i >> 1];
            }
        }

        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);

        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - j);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) {
        if (I) {
            int j = log[r - l + 1];
            return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
        }

        T ans = 0; //identity element of f
        for (int j = mat.size() - 1; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans = f(ans, mat[j][l]);
                l += (1 << j);
            }
        }
        return ans;
    }
};
