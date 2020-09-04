class Matching {
public:
    Graph g;
    vector<int> c, match;
    vector<bool> visited;

    Matching(Graph& g): g(g), c(g.n, -1), match(g.n, -1), visited(g.n) {}

    void dfs(int x, int h) {
        c[x] = h;
        for (int &i : g[x]) {
            if (c[i] == -1)
                dfs(i, h ^ 1);
        }
    }
    bool dfs(int x) {
        for (int &i : g[x]) {
            if (!visited[i]) {
                visited[i] = true;
                if (match[i] < 0 or dfs(match[i])) {
                    match[i] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int size() {
        for (int i = 0; i < g.n; i++) {
            if (c[i] == -1)
                dfs(i, 0);
        }
        for (auto &[u, v] : g.edges) {
            if (c[u] == c[v])
                return -1;
        }
        int matching = 0;
        for (int x = 0; x < g.n; x++) {
            if (!c[x]) {
                fill(visited.begin(), visited.end(), false);
                matching += dfs(x);
            }
        }
        return matching;
    }
};
