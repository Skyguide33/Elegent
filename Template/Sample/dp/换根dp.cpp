
// https://www.luogu.com.cn/problem/P3478
// 换根dp
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define PII pair<int, int>
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int inf = 2e9 + 10;
const int N = 1e6 + 5;
// const int P = 998244353;
const int P = 1e9 + 7;

int n;
int head[N], ne[N << 1], to[N << 1], cnt = 1;
void add(int u, int v) {
    to[cnt] = v;
    ne[cnt] = head[u];
    head[u] = cnt++;
}

int sz[N], dp[N];

void dfs1(int u, int f) {
    sz[u] = 1;
    dp[u] = 0;
    for (int e = head[u], v;e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + 1;
    }
}
int ans = 1, mx;
void dfs2(int u, int f) {
    for (int v, e = head[u];e;e = ne[e]) {
        v = to[e];
        if (v == f)continue;
        dp[v] = dp[u] - sz[v] + n - sz[v];
        if (dp[v] > mx) {
            mx = dp[v];
            ans = v;
        }
        dfs2(v, u);
    }
}



void solve() {
    cin >> n;
    int u, v;
    for (int i = 1;i < n;i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs1(1, 0);
    mx = dp[1];
    dfs2(1, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // per();
    // cin >> TT;
    while (TT--)
        solve();
    return 0;
}