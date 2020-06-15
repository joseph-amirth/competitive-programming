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

        for (pair<int, int> &i : g[u]) {
            if (d[i.first] > d[u] + i.second) {
                d[i.first] = d[u] + i.second;
                q.push({d[i.first], i.first});
            }
        }
    }
}
