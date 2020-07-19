class UnionFind {
public:
    int n;
    vector<int> p, r;
    explicit UnionFind(int n = 0): n(n), p(n + 1), r(n + 1) {
        iota(all(p), 0);
    }
    int size() const {
        return n;
    }
    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
    void union_find(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 != l2) {
            if (r[l1] > r[l2])
                p[l2] = l1;
            else if (r[l1] < r[l2])
                p[l1] = l2;
            else {
                p[l2] = l1;
                r[l1]++;
            }
            n--;
        }
    }
};
