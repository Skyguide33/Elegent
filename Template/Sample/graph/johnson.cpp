#include <bits/stdc++.h>

using namespace std;

using ll = long long;
// #define int ll
const int N = 3e3 + 5;

int n, m;
struct edge
{
    int v;
    int w;
};
vector<edge> e[N];
ll d[N], h[N]; // 势能数组
int vis[N];
int cnt[N];

void spfa()
{
    queue<int> q;
    memset(h, 63, sizeof h);
    memset(vis, false, sizeof vis);
    h[0] = 0;
    vis[0] = 1;
    q.push(0);
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n)
                {
                    cout << "-1\n";
                    exit(0);
                }
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
}

void djs(int s)
{
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++)
        d[i] = 1e9;
    priority_queue<pair<ll, int>> q;
    d[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                    q.push({-d[v], v});
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        e[0].push_back({i, 0}); // 加虚拟边
    spfa();
    for (int u = 1; u <= n; u++)
        for (auto &ed : e[u])
            ed.w += h[u] - h[ed.v]; // 构造新边
    for (int i = 1; i <= n; i++)
    {
        djs(i);
        ll ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (d[j] == 1e9)
                ans += (ll)j * d[j];
            else
                ans += (ll)j * (d[j] + h[j] - h[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
