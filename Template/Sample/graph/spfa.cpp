
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;
struct edge {
    int v, w;
};
int n, m, s;
vector<edge> e[N];
int d[N]; // 距离
int cnt[N], vis[N];
queue<int> q;

bool spfa(int s) {
    for (int i = 0; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return 1;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
    return 0;
}

signed main() {
    cin >> n >> m >> s;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back({ b, c });
    }
    if (!spfa(s))
        for (int i = 1; i <= n; i++)
            cout << d[i] << ' ';
    return 0;
}