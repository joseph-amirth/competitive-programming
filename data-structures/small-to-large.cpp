class UnionFind { //union find but with small to large merging
public:
    int n;
    vector<int> p;
    vector<vector<int>> cmps;

    UnionFind(): n(), p(), cmps() {}
    UnionFind(int n): n(n), p(n + 1), cmps(n + 1) {
        iota(all(p), 0);
        for (int i = 1; i <= n; i++) cmps[i] = {i};
    }
    int size() const {
        return n;
    }
    int find(int x) {
        return p[x];
    }
    bool merge(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 == s2)
            return false;
        if (cmps[s2].size() > cmps[s1].size())
            swap(s1, s2);
        for (int i : cmps[s2]) {
            cmps[s1].push_back(i);
            p[i] = s1;
        } cmps[s2].clear();

        n--;
        return true;
    }
};
