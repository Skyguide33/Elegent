#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 5e5 + 5;

int head[N], to[N << 1], ne[N << 1], W[N << 1], tot = 1;

void add(int u, int v, int w) {
    to[tot] = v;
    W[tot] = w;
    ne[tot] = head[u];
    head[u] = tot++;
}

int n;
//ans开成数组，可以得出每一个点：经过该点的最远距离
ll ans = 0, d[N];//只能往下走能到达的最远距离

void dp(int u, int f) {
    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        dp(v, u);
    }

    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        ans = max(ans, d[u] + d[v] + W[e]);
        d[u] = max(d[u], d[v] + W[e]);
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
    dp(1, 0);
    cout << ans << '\n';
}

int main() {

    solve();
    return 0;
}