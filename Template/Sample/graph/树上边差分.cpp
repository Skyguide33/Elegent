#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 5;

const int P = 25;
int head[N], to[N << 1], ne[N << 1], W[N << 1], tot = 1;

void add(int u, int v, int w) {
    to[tot] = v;
    ne[tot] = head[u];
    W[tot] = w;
    head[u] = tot++;
}

int st[N][P];
int dep[N];

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
        if (dep[st[u][p]] >= dep[v])
            u = st[u][p];

    if (v == u)return u;

    for (int p = 20;p >= 0;p--)
        if (st[u][p] != st[v][p])
            u = st[u][p], v = st[v][p];

    return st[u][0];
}

int a[N], c[N];
void change(int u, int v, int w) {
    int res = lca(u, v);
    c[u] += w;
    c[v] += w;
    c[res] -= 2 * w;
}

void dfs2(int u) {
    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == st[u][0])continue;
        dfs2(v);
        c[u] += c[v];
        W[e] += c[v];
    }
}

void solve() {

}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}