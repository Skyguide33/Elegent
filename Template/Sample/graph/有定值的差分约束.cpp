// 倍杀测量者
// 如果 A的分数 >= B的分数 * k，k是正实数，就称 A k倍杀 B，或称 B被A k倍杀了
// 一场比赛中，一共有n个选手，有m1条誓言记录，有m2条选手得分记录，得分只可能是正实数
// 类型1的誓言 u v k : 选手u 没有k倍杀 选手v，那么选手u就穿女装
// 类型2的誓言 u v k : 选手u 被选手v k倍杀了，那么选手u就穿女装
// 选手的得分    u w : 选手u得了w分，如果某选手没有得分记录，按照尽量不穿女装的情况推测
// 你希望看到比赛后有人穿女装，但不想看到很多人穿女装，于是想制定正实数ans，效果如下
// 类型1的誓言，比例调整成(k-ans)，类型2的誓言，比例调整成(k+ans)，即提高了穿女装的条件
// 计算ans最大多少，依然有人穿女装，保留小数点后4位，如果不干预也没人穿女装，返回-1
// 1 <= n, m1, m2 <= 1000
// 1 <= k <= 10
// 1 <= w <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4926

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll


const int inf = 1e9 + 10;
const int N = 3e3 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

int n, s, t;
int f[N][4];
int c[N][2];
double sml = 1e-6;
int tot = 1;
int head[N << 1], ne[N << 1], to[N << 1], vis[N], cnt[N];
double W[N << 1];
double d[N];
void init() {
    tot = 1;
    for (int i = 0;i <= n + 2;i++)
        head[i] = 0, W[i] = 0, vis[i] = 0, d[i] = inf, cnt[i] = 0;
}

void add(int u, int v, double w) {
    to[tot] = v;
    ne[tot] = head[u];
    W[tot] = w;
    head[u] = tot++;
}

bool spfa(int x) {
    d[x] = 0;
    vis[x] = 1;
    queue<int>q;
    q.push(x);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int e = head[u];e;e = ne[e]) {
            int v = to[e];
            double w = W[e];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n + 2)
                    return 1;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}


bool check(double x) {
    init();
    // 0号点是连通超级源点，保证图的连通
    for (int i = 1;i <= n;i++)
        add(0, i, 0);
    for (int i = 1;i <= s;i++) {
        if (f[i][0] == 1) {
            add(f[i][1], f[i][2], -log2(-x + f[i][3]));
        } else {
            // 因为类型2的誓言是<关系，所以减去最小精度后，就可以认为是<=关系
            add(f[i][1], f[i][2], log2(x + f[i][3] - sml));
        }
    }

    // n+1号点是限制超级源点，保证确定得分的选手之间的关系
    // 本题测试数据有限，两个超级源点合并居然也能通过
    // 原理上两个超级源点一定要分开
    for (int i = 1;i <= t;i++) {
        add(n + 1, c[i][0], log2(c[i][1]));
        add(c[i][0], n + 1, -log2(c[i][1]));
    }
    return spfa(0);
}


void solve() {
    cin >> n >> s >> t;
    for (int i = 1;i <= s;i++) {
        cin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
    }
    for (int i = 1;i <= t;i++) {
        cin >> c[i][0] >> c[i][1];
    }

    //二分答案
    double l = 0, r = 1e10, m, ans = 0;
    while (r - l >= sml) {
        m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m + sml;
        } else {
            r = m - sml;
        }
    }

    if (ans < sml) {
        cout << -1 << '\n';
    } else  cout << fixed << setprecision(8) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;

    // cin >> TT;
    while (TT--)
        solve();
    return 0;
}
