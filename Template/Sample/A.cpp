#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define PII pair<int, int>
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int inf = 1e9 + 10;
const int N = 1e3 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

int n, s, t;
int f[N][4];
int c[N][2];
double sml = 1e-6;
int tot = 1;
int head[N << 1], ne[N << 1], to[N << 1], vis[N], cnt[N];
double W[N << 1];
double d[N];
void init() {
    tot = 1;
    for (int i = 0;i <= n + 2;i++)
        head[i] = 0, W[i] = 0, vis[i] = 0, d[i] = inf, cnt[i] = 0;
}

void add(int u, int v, double w) {
    to[tot] = v;
    ne[tot] = head[u];
    W[tot] = w;
    head[u] = tot++;
}

bool spfa(int x) {
    for (int i = 0; i <= n + 1; i++) {
        d[i] = inf;
        vis[i] = 0;
        cnt[i] = 0;
    }
    d[x] = 0;
    vis[x] = 1;
    queue<int>q;
    q.push(x);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int e = head[u];e;e = ne[e]) {
            int v = to[e];
            double w = W[e];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n + 2)
                    return true;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

bool check(double x) {
    init();
    for (int i = 1;i <= n;i++)
        add(0, i, 0);
    for (int i = 1;i <= s;i++) {
        if (f[i][0] == 1) {
            add(f[i][1], f[i][2], -log(-x + f[i][3]));
        } else {
            add(f[i][1], f[i][2], log(x + f[i][3] - sml));
        }
    }
    for (int i = 1;i <= t;i++) {
        add(n + 1, c[i][0], log(c[i][1]));
        add(c[i][0], n + 1, -log(c[i][1]));
    }
    return spfa(0);
}

void solve() {
    cin >> n >> s >> t;
    for (int i = 1;i <= s;i++) {
        cin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
    }
    for (int i = 1;i <= t;i++) {
        cin >> c[i][0] >> c[i][1];
    }
    double l = 0, r = 10, m, ans = 0; // k<=10，所以r=10足够
    while (r - l >= sml) {
        m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m + sml;
        } else {
            r = m - sml;
        }
    }
    if (ans < 1e-8) { // 判断ans是否为0
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;

    // cin >> TT;
    while (TT--)
        solve();
    return 0;
}