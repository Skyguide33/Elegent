#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 2e5 + 5;

int n, m;
vector<int> e[N], tp; // 邻点  拓扑序
int din[N];           // 入度

// 广搜算法
bool toposort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!din[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        tp.push_back(x);
        for (auto u : e[x])
        {
            if (--din[u] == 0)
                q.push(u);
        }
    }
    return tp.size() == n;
}

// 深搜算法
int c[N]; // 染色数组
bool dfs(int x)
{
    c[x] = -1;         // 进入后染色为-1
    for (int y : e[x]) // 枚举子节点
    {
        if (c[y] < 0) // 如果子节点为-1，则有环返回
            return 0;
        if (!c[y])
            if (!dfs(y))
                return 0;
    }
    c[x] = 1; // 染色为1
    tp.push_back(x);
    return 1;
}

bool topo()
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
        if (!c[i])
            if (!dfs(i))
                return 0;
    reverse(tp.begin(), tp.end());
    return 1;
}

signed main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        e[a].push_back(b);
        din[b]++;
    }
    if (!topo())
        puts("-1");
    else
        for (auto x : tp)
            cout << x << ' ';
    return 0;
}