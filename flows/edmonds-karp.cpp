class EdmondsKarp { //not the best algo for maxflow
public:
    FlowGraph g;
    vector<int> p;

    EdmondsKarp(FlowGraph& g): g(g), p(g.n) {}

    bool bfs() {
        fill(p.begin(), p.end(), 0);

        queue<int> q;
        q.emplace(g.s);
        p[g.s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &i : g[u]) {
                const auto edge = g.e[i];
                if (!p[edge.v] and edge.c - edge.f) {
                    p[edge.v] = i;
                    if (edge.v == g.t)
                        return true;
                    q.push(edge.v);
                }
            }
        }
        return false;
    }

    int maxFlow() {
        int flow = 0;

        while (bfs()) {
            int pathFlow = inf;
            for (int x = g.t; x != g.s; x = g.e[p[x]].u) {
                pathFlow = min(pathFlow, g.e[p[x]].c - g.e[p[x]].f);
            }

            for (int x = g.t; x != g.s; x = g.e[p[x]].u) {
                int i = p[x];
                g.e[i].f += pathFlow;
                g.e[i ^ 1].f -= pathFlow;
            }
            flow += pathFlow;
        }
        return flow;

};
