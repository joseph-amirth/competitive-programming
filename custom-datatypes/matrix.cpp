template <typename T> class matrix {
public:
    int n, m;
    vector<vector<T>> mat;

    matrix(): n(), m(), mat() {}
    matrix (int n, int m): n(n), m(m), mat(n, vector<T>(m)) {}

    vector<T>& operator[](const int& idx) {
        return mat[idx];
    }

    matrix operator*(matrix& rhs) {
        assert(m == rhs.n);
        matrix res(n, rhs.m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rhs.m; j++) {
                res[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    res[i][j] += mat[i][k] * rhs[k][j];
                }
            }
        }
        return res;
    }

    matrix operator*=(matrix& rhs) {
        return *this = *this * rhs;
    }
};
