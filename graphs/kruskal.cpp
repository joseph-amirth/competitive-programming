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

    using edge = Graph::edge;

    vector<edge> MST() {
        sort(g.e.begin(), g.e.end(), [&] (const edge& a, const edge& b) {
            return a.w < b.w;
        });
        vector<edge> mst;
        for (auto &[u, v, w] : g.e) {
            if (merge(u, v)) {
                mst.emplace_back(u, v, w);
            }
        }
        return mst;
    }
};
