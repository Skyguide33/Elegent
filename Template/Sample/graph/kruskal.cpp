#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 3e5 + 5;

struct edge
{
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w < t.w;
    }
} e[N];
int n, m;
ll fa[N], ans, cnt;
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
bool kruskal()
{
    sort(e, e + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x != y)
        {
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    return cnt == n - 1;
}

signed main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    if (kruskal())
        cout << ans << '\n';
    else
        cout << "orz\n";
    return 0;
}