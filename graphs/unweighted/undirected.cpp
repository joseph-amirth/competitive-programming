class Graph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    vector<int>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
        m++;
    }
};
