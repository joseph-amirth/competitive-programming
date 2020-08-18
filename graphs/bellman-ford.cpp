ll dp[N][N], dist[N];

void BellmanFord(int s) {
    for (int i = 1; i <= n; i++)
        dp[i][0] = inf;
    dp[s][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[j][i-1];
            for (auto &[v, w] : g[j]) {
                if (dp[v][i - 1] != inf)
                    dp[j][i] = min(dp[j][i], dp[v][i - 1] + w);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dist[i] = dp[i][n - 1];
}
