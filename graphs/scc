void computeSCC() {
    int s = 0, cur = 0;
    function<void(int)> dfs1 = [&](int x) {
        visited[x] = true;

        for (int &i : grev[x]) {
            if (!visited[i])
                dfs1(i);
        }

        cur += 1;
        f[cur] = x;
    };

    function<void(int)> dfs2 = [&](int x) {
        visited[x] = true;
        scc[s].push_back(x);

        for (int &i : g[x]) {
            if (!visited[i])
                dfs2(i);
        }
    };

    fill(visited, visited + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs1(i);
    }

    fill(visited, visited + n + 1, false);

    for (int i = n; i >= 1; i--) {
        if (!visited[f[i]]) {
            s = f[i];
            dfs2(f[i]);
        }
    }
}
