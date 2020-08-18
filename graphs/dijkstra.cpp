int dist[N];
bool visited[N];

void Dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    fill(dist, dist + n + 1, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, s);

    dist[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}
