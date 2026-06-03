#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int n, m;

struct edge
{
    int v, w;
};

vector<edge> e[N];
int d[N], vis[N];
priority_queue<pair<int, int>> q;
ll ans = 0;

bool prim(int s)
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        ans += d[u];
        cnt++;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > w)
            {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
    return cnt == n;
}

signed main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    if (prim(1))
        cout << ans << '\n';
    return 0;
}