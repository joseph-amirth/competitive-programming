class DiGraph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    DiGraph(): n(), m(), adj(), edges() {}
    DiGraph(int n): n(n), m(), adj(n), edges() {}

    vector<int>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        edges.emplace_back(u, v);
        m++;
    }

    DiGraph transpose() const {
        DiGraph rev(n);
        for (auto &[u, v] : edges) {
            rev.addEdge(v, u);
        }
        return rev;
    }
};
