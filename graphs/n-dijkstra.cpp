int d[N][N];
bool visited[N];

void nDijkstra(int s) {
    function<void(int)> dijkstra = [&](int s) {
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

            for (pair<int, int> &i : g[u]) {
                if (d[s][i.first] > d[s][u] + i.second) {
                    d[s][i.first] = d[s][u] + i.second;
                    q.push({d[s][i.first], i.first});
                }
            }
        }
    };
    for (int i = 1; i <= n; i++)
        dijkstra(i);
}
