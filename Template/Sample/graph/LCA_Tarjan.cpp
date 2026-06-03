

#include <bits/stdc++.h>

using namespace std;
#define PII pair<int, int>
using ll = long long;
const int N = 5e5 + 5;

vector<int> e[N];
vector<PII> query[N];
int fa[N], vis[N], ans[2 * N];
int n, m, s, a, b;
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void tarjan(int x) {
    vis[x] = 1; // 标记已访问
    for (auto y : e[x])
        if (!vis[y]) {
            tarjan(y);
            fa[y] = x; // 回到时标记父亲x
        }
    // 离开x时找LCA
    for (auto [y, i] : query[x]) {
        if (vis[y])
            ans[i] = find(y);
    }
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        query[a].push_back({ b, i });
        query[b].push_back({ a, i });
    }
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    tarjan(s);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}