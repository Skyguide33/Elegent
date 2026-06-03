#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;
struct edge
{
    int v, w;
};
int n, m, s;
vector<edge> e[N];
int d[N]; // 距离

bool bellmanford(int s)
{
    for (int i = 0; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        flag = false;
        for (int u = 1; u <= n; u++)
        {
            if (d[u] == 1e9)
                continue;
            for (auto ed : e[u])
            {
                int v = ed.v, w = ed.w;
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    flag = 1;
                }
            }
        }
        if (!flag)
            break;
    }
    return flag; // 第n轮=true则有负环
}

signed main()
{
    cin >> n >> m >> s;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back({b, c});
    }
    if (!bellmanford(s))
        for (int i = 1; i <= n; i++)
            cout << d[i] << ' ';
    return 0;
}