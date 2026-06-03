//树的直径，两次dfs法 **边权不能为负数**
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 5e5 + 5;

int head[N], to[N << 1], ne[N << 1], W[N << 1], cnt = 1;

void add(int u, int v, int w) {
    to[cnt] = v;
    ne[cnt] = head[u];
    W[cnt] = w;
    head[u] = cnt++;
}

int n;
int d[N], pre[N];

void dfs(int u, int f) {
    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        d[v] = d[u] + W[e];
        pre[v] = u;
        dfs(v, u);
    }
}


void solve() {
    cin >> n;
    int u, v, w;
    for (int i = 1;i < n;i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0);
    int s = 1, mx = 0;
    for (int i = 1;i <= n;i++) {
        if (d[i] > mx) {
            mx = d[i];
            s = i;
        }
    }
    d[s] = 0;
    dfs(s, 0);
    mx = 0;
    for (int i = 1;i <= n;i++)mx = max(mx, d[i]);
    // for (int i = 1;i <= n;i++)cout << d[i] << ' ';
    cout << mx;
}

signed main() {

    solve();
    return 0;
}