int d[N][N];
bool visited[N];

void Dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    fill(d[s], d[s] + n + 1, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});

    d[s][s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (d[s][v] > d[s][u] + w) {
                d[s][v] = d[s][u] + w;
                q.push({d[s][v], v});
            }
        }
    }
}

void nDijkstra() { //apsp
    for (int i = 1; i <= n; i++)
        dijkstra(i);
}
