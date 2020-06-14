int d[N], dp[N][N];

void BellmanFord(int s) {
    fill(dp, dp + n + 1, inf);
    dp[s][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[j][i-1];
            for (auto &x : g[j]) {
                dp[j][i] = min(dp[j][i], dp[x.first][i-1] + x.second);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = dp[n][n - 1];
}
