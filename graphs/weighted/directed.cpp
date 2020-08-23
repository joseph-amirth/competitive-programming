class DiGraph {
public:
    struct edge {
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<pair<int, int>>> adj;

    DiGraph(): n(), m(), adj(), edges() {}
    DiGraph(int n): n(n), m(), adj(n), edges() {}

    vector<pair<int, int>>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        edges.emplace_back(u, v, w);
        m++;
    }

    DiGraph transpose() const {
        DiGraph rev(n);
        for (int i = 1; i <= n; i++) {
            for (auto &[v, w]: adj[i])
                rev.addEdge(v, i, w);
        }
        return rev;
    }
};
