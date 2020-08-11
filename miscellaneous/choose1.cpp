bool computed;
ll c[N + 1][N + 1];

ll choose(int n, int k) {
    if (!computed) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 or j == i)
                    c[i][j] = 1;
                else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        computed = true;
    }
    return c[n][k];
}
