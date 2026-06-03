// 墨墨的等式(两次转圈法)
// 一共有n种正数，每种数可以选择任意个，个数不能是负数
// 那么一定有某些数值可以由这些数字累加得到
// 请问在[l...r]范围上，有多少个数能被累加得到
// 0 <= n <= 12
// 0 <= 数值范围 <= 5 * 10^5
// 1 <= l <= r <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P2371
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll


const ll inf = 2e18 + 10;
const int N = 5e5 + 5;
// const int P = 998244353;
const int P = 1e9 + 7;

int n;
ll l, r;
ll d[N];

void solve() {
    cin >> n >> l >> r;
    vector<int>a(n);
    int x = inf;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i])//a[i]==0舍去
            x = min(x, a[i]);
    }
    // sort(a.begin(), a.end());
    // x = a[0];
    for (int i = 1;i < x;i++)d[i] = inf;
    d[0] = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] == 0 || a[i] == x)continue;
        int gcd = __gcd(a[i], x);//共有gcd个环
        for (int j = 0;j < gcd;j++) {
            for (int cur = j, ne, cnt = 0; cnt < 2;cnt += cur == j) {//两次绕圈
                ne = (cur + a[i]) % x;
                if (d[cur] != inf)
                    d[ne] = min(d[ne], d[cur] + a[i]);
                cur = ne;
            }
        }
    }

    l--;
    ll ans = 0;
    for (int i = 0;i < x;i++) {
        // cout << d[i] << ' ';
        if (d[i] <= r)ans += (r - d[i]) / x + 1;
        if (d[i] <= l)ans -= (l - d[i]) / x + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // per();
    // cin >> TT;
    while (TT--)
        solve();
    return 0;
}