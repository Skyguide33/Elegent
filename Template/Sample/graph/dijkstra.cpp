#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<int, int>
const int N = 2e5 + 5;

struct edge
{
    int v, w;
};
vector<edge> e[N];
int d[N], v[N], pre[N];
priority_queue<PII> q; // 距离 编号
int n, s;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (v[u])
            continue;
        v[u] = 1;
        for (auto x : e[u])
        {
            int v = x.v, w = x.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pre[v] = u;
                q.push({-d[v], v});
            }
        }
    }
}

void dfs(int u)
{
    if (u == s)
    {
        cout << u << ' ';
        return;
    }

    dfs(pre[u]);
    cout << u << ' ';
}

signed main()
{
    int m;
    cin >> n >> m >> s;
    int a, b, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        e[a].push_back({b, w});
    }
    dijkstra(s);
    for (int i = 2; i <= n; i++)
    {
        cout << "ans:";
        dfs(i);
        cout << '\n';
    }

    return 0;
}