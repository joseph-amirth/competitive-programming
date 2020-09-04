class FlowGraph {
public:
    struct edge {
        int u, v, c, f;
        edge(int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
    };

    int n, m, s, t;
    vector<edge> edges;
    vector<vector<int>> adj;

    FlowGraph(): n(), m(), s(), t(), edges(), adj() {}
    FlowGraph(int n, int s, int t): n(n), m(), s(s), t(t), edges(), adj(n) {}

    vector<int>& operator[](const int& idx) {
        return adj[idx];
    }

    void addEdge(int u, int v, int c) {
        edges.emplace_back(u, v, c, 0);
        adj[u].push_back(m);
        m++;

        edges.emplace_back(u, v, c, c);
        adj[v].push_back(m);
        m++;
    }
};
