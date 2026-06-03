#include <bits/stdc++.h>

using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 5e5 + 5;

int n, m, s, a, b;
vector<int> e[N];
int fa[N], sz[N], dep[N], son[N], top[N];

// 找父节点，重儿子，深度fa,son,dep
void dfs1(int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    for (int v : e[u])
    {
        if (v == fa[u])
            continue;
        dfs1(v, u);
        // 回时添加节点数
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}

// 找top
void dfs2(int u, int t)
{
    top[u] = t; // 记录链头
    if (!son[u])
        return;      // 叶节点无重儿子
    dfs2(son[u], t); // 搜重儿子
    for (int v : e[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v); // 搜轻儿子
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
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
    dfs1(s, 0);
    dfs2(s, s);
    while (m--)
    {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}