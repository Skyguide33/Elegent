// 牛场围栏
// 给定一个长度为n的数组arr, arr[i]代表第i种木棍的长度，每种木棍有无穷多个
// 给定一个正数m，表示你可以把任何一根木棍消去最多m的长度，同一种木棍可以消去不同的长度
// 你可以随意拼接木棍形成一个长度，返回不能拼出来的长度中，最大值是多少
// 如果你可以拼出所有的长度，返回-1
// 如果不能拼出来的长度有无穷多，返回-1
// 1 <= n <= 100
// 1 <= arr[i] <= 3000
// 1 <= m <= 3000
// 测试链接 : https://www.luogu.com.cn/problem/P2662
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
// #define int ll;
const int N = 3e3 + 5;
const int M = 2e6;
const int inf = 2e9 + 10;
int n, m;
int x;
ll d[N];
int head[N], to[M], ne[M], cnt = 1;
ll W[M];
void add(int u, int v, ll w) {
    to[cnt] = v;
    ne[cnt] = head[u];
    W[cnt] = w;
    head[u] = cnt++;
}

int a[N];
bool f[N];
struct node {
    int v;
    ll w;
    bool operator<(const node& t)const {
        return w > t.w;
    }
};
bool vis[N];
void djs() {
    for (int i = 0;i < x;i++)d[i] = inf;
    d[0] = 0;
    priority_queue<node>q;
    q.push({ 0,0 });
    while (q.size()) {
        auto [u, w] = q.top();
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int v, e = head[u];e;e = ne[e]) {
            v = to[e];
            if (d[v] > d[u] + W[e]) {
                d[v] = d[u] + W[e];
                q.push({ v,d[v] });
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] < a[1])swap(a[1], a[i]);//选取最小的值为基准
    }
    // sort(a+1,a+n+1);
    if (a[1] - m <= 1) {
        cout << -1 << '\n';
        return;
    }
    x = a[1] - m;
    for (int i = 1;i <= n;i++) {
        for (int j = a[i] - m;j <= a[i];j++) {
            if (f[j])continue;//确保每条边只被添加一次
            f[j] = 1;
            for (int k = 0;k < x;k++) {//根据余数分成x组
                add(k, (k + j) % x, j);//转移，边权为j
            }
        }
    }
    djs();
    ll ans = 0;
    for (int i = 0;i < x;i++) {
        if (d[x] == inf) {
            cout << -1 << '\n';
            return;
        }
        ans = max(ans, d[i] - x);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}