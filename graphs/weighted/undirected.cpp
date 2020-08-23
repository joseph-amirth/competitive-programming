class Graph {
public:
    struct edge {
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<pair<int, int>>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    vector<pair<int, int>>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
        m++;
    }
};
