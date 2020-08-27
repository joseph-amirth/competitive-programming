class Kruskal {
public:
    Graph g;
    vector<int> p, r;

    Kruskal(Graph& g): g(g), p(g.n), r(g.n) {
        iota(p.begin(), p.end(), 0);
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
        return true;
    }

    vector<int> MST() {
        vector<int> temp(g.m);
        iota(temp.begin(), temp.end(), 0);

        sort(temp.begin(), temp.end(), [&] (const int& i, const int& j) {
            return g.e[i].w < g.e[j].w;
        });

        vector<int> mst;
        for (int i : temp) {
            if (merge(g.e[i].u, g.e[i].v))
                mst.push_back(i);
        }
        return mst;
    }
};
