class Kosaraju {
public:
    DiGraph g, grev;
    int T;
    vector<int> f, visited;

    Kosaraju(DiGraph& g): g(g), T(), f(g.n), visited(g.n) {
        grev = g.transpose();
    }
    void dfs(int x) {
        visited[x] = true;
        for (int &i : grev[x]) {
            if (!visited[i])
                dfs(i);
        }
        f[T++] = x;
    }
    void dfs(int x, int s, vector<int>& v) {
        visited[x] = true;
        v[x] = s;

        for (int &i : g[x]) {
            if (!visited[i])
                dfs(i);
        }
    }
    vector<int> SCC() {
        for (int i = 0; i < g.n; i++) {
            if (!visited[i])
                dfs(i);
        }
        fill(visited.begin(), visited.end(), false);
        vector<int> v(g.n);

        for (int i = g.n - 1; i >= 0; i--) {
            if (!visited[f[i]]) {
                dfs(f[i], f[i], v);
            }
        }
        return v;
    }
};
