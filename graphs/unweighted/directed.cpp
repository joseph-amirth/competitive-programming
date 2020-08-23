class DiGraph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> e;
    vector<vector<int>> adj;

    DiGraph(): n(), m(), adj(), e() {}
    DiGraph(int n): n(n), m(), adj(n), e() {}

    vector<int>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        e.emplace_back(u, v);
        m++;
    }

    DiGraph transpose() const {
        DiGraph rev(n);
        for (int i = 0; i < n; i++) {
            for (int x : adj[i])
                rev.addEdge(x, i);
        }
        return rev;
    }
};
