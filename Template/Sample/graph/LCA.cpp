#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 5e5 + 5;

int n, m, s, a, b;
vector<int> e[N];
int dep[N], fa[N][20];

void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];

    for (int v : e[u])
        if (v != f)
            dfs(v, u);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    // 跳到同一层
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v)
        return v;
    // 共同跳到lca的下一层
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
signed main()
{
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(s, 0);
    while (m--)
    {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}