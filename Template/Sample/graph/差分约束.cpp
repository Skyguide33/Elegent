// 布局奶牛
// 编号1到编号n的奶牛从左往右站成一排，你可以决定任意相邻奶牛之间的距离
// 有m1条好友信息，有m2条情敌信息，好友间希望距离更近，情敌间希望距离更远
// 每条好友信息为 : u v w，表示希望u和v之间的距离 <= w，输入保证u < v
// 每条情敌信息为 : u v w，表示希望u和v之间的距离 >= w，输入保证u < v
// 你需要安排奶牛的布局，满足所有的好友信息和情敌信息
// 如果不存在合法方案，返回-1
// 如果存在合法方案，返回1号奶牛和n号奶牛之间的最大距离
// 如果存在合法方案，并且1号奶牛和n号奶牛之间的距离可以无穷远，返回-2
// 测试链接 : https://www.luogu.com.cn/problem/P4878


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

const int inf = 1e18;
const int N = 1e3 + 5;

struct edge {
    int v, w;
};
vector<edge> e[N];

int vis[N], cnt[N], d[N];
int n, m1, m2;

bool spfa(int s) {
    for (int i = 0; i <= n; i++) {
        d[i] = inf;
        vis[i] = 0;
        cnt[i] = 0;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return true; // 负环
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m1 >> m2;


    // 超级源点
    for (int i = 1; i <= n; i++) e[0].push_back({ i, 0 });

    // 好友约束: u v w -> d[v] <= d[u] + w
    for (int i = 0; i < m1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({ v, w });
    }

    // 情敌约束: u v w -> d[u] <= d[v] - w  
    for (int i = 0; i < m2; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[v].push_back({ u, -w });
    }

    // 位置约束: d[i] <= d[i+1]
    for (int i = 1; i < n; i++) {
        e[i + 1].push_back({ i, 0 });
    }

    // 检查约束可行性
    if (spfa(0)) {
        cout << -1 << '\n';
        return;
    }

    // 计算1到n的最大距离
    spfa(1);
    if (d[n] == inf) {
        cout << -2 << '\n';
    } else {
        cout << d[n] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    while (TT--)
        solve();
    return 0;
}