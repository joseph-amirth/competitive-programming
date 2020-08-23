class FlowGraph {
public:
    struct flowEdge {
        int u, v, c, f;
        flowEdge(int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
    };

    int n, m, s, t;
    vector<flowEdge> e;
    vector<vector<int>> adj;

    FlowGraph(): n(), m(), s(), t(), e(), adj() {}
    FlowGraph(int n, int s, int t): n(n), m(), s(s), t(t), e(), adj(n) {}

    vector<int>& operator[](const int& idx) {
        return adj[idx];
    }

    void addEdge(int u, int v, int c) {
        e.emplace_back(u, v, c, 0);
        adj[u].push_back(m);
        m++;

        e.emplace_back(u, v, c, c);
        adj[v].push_back(m);
        m++;
    }
};
