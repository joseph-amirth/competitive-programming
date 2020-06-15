const int B = 447;

struct query {
    int l, r, id;
}q[N];

bool comp (query x, query y) {
    if (x.l/B != y.l/B)
        return x.l/B < y.l/B;
    return x.r < y.r;
}

int n, a[N], ans[N], cur = 0;

void add (int x) {

}

void remove (int x) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;  --q[i].l; --q[i].r;
        q[i].id = i;
    }

    sort(q, q + m, comp);

    int cur_l = 0, cur_r = 0;
    add(0);

    for (int i = 0; i < m; i++) {
        while (q[i].l < cur_l) {
            add(cur_l - 1);
            cur_l -= 1;
        }

        while (q[i].l > cur_l) {
            remove(cur_l);
            cur_l += 1;
        }

        while (q[i].r < cur_r) {
            remove(cur_r);
            cur_r -= 1;
        }

        while (q[i].r > cur_r) {
            add(cur_r + 1);
            cur_r += 1;
        }

        ans[q[i].id] = cur;
    }

    for (int i = 0; i < m; i++) cout << ans[i] << "\n";

    return 0;
}
