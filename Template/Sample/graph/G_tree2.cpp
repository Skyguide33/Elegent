// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 5e4 + 5;
const int inf = 1e9 + 10;
int n;
int head[N], ne[N], to[N], cnt = 1;

void add(int u, int v) {
    ne[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

int sz[N];

int ans = 0, mx = inf;

void dfs(int u, int f) {
    sz[u] = 1;
    int son = 0;
    for (int e = head[u];e;e = ne[e]) {
        int v = to[e];
        if (v == f)continue;
        dfs(v, u);
        son = max(son, sz[v]);
        sz[u] += sz[v];
    }
    son = max(son, n - sz[u]);
    if (son < mx || (son == mx && ans > u)) {
        mx = son;
        ans = u;
    }
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i++)head[i] = 0;
    cnt = 1;
    ans = 0;
    mx = inf;
    for (int i = 1, u, v;i < n;i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    cout << ans << ' ' << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}