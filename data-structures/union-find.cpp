class UnionFind {
public:
    int n;
    vector<int> p, r;

    UnionFind(): n(), p(), r() {}
    UnionFind(int n): n(n), p(n + 1), r(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int size() const {
        return n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 == l2)
            return false;
        if (r[l1] > r[l2])
            p[l2] = l1;
        else if (r[l1] < r[l2])
            p[l1] = l2;
        else {
            p[l2] = l1;
            r[l1]++;
        }
        n--;
        return true;
    }
};
