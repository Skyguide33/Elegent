#include<bits/stdc++.h>

using namespace std;

#define ll long long 

const int N = 1e5;

const int P = 25;

int head[N], to[N << 1], ne[N << 1], tot = 1;

void add(int u, int v) {
    to[tot] = v;
    ne[tot] = head[u];
    head[u] = tot++;
}

int st[N][P];
int dep[N];
int a[N], c[N];

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    st[u][0] = f;

    for (int p = 1;(1 << p) <= dep[u];p++)
        st[u][p] = st[st[u][p - 1]][p - 1];

    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v])swap(u, v);

    for (int p = 20;p >= 0;p--)
        if (dep[st[u][p]] >= dep[v])u = st[u][p];
    if (u == v)return u;

    for (int p = 20;p >= 0;p--)
        if (st[u][p] != st[v][p]) {
            u = st[u][p];
            v = st[v][p];
        }

    return st[u][0];
}

void change(int u, int v, int w) {
    c[u] += w;
    c[v] += w;
    int res = lca(u, v);
    c[res] -= w;
    c[st[res][0]] -= w;
}

void dfs(int u) {
    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == st[u][0])continue;
        dfs(v);
        c[u] += c[v];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    while (m--) {
        int u, v, w;
        cin >> u >> v;
        change(u, v, 1);
    }
    dfs(1);
    int ans = 0;
    for (int i = 1;i <= n;++i)ans = max(ans, c[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();
    return 0;
}
