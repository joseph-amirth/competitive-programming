int d[N];
bool visited[N];

void Dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    fill(d, d + n + 1, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});

    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}
