//三分搜索 （适用单峰函数）
// https://codeforces.com/problemset/problem/2132/E
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 5;

int n, m, q;

void solve() {
    cin >> n >> m >> q;
    vector<ll>a(n + 1), b(m + 1), sa(n + 1), sb(m + 1);
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (int i = 1;i <= m;i++)cin >> b[i];
    sort(a.begin() + 1, a.end(), greater<ll>());
    sort(b.begin() + 1, b.end(), greater<ll>());
    for (int i = 1;i <= n;i++)sa[i] = sa[i - 1] + a[i];
    for (int i = 1;i <= m;i++)sb[i] = sb[i - 1] + b[i];

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int l = max(0, z - y), r = min(z, x);
        while (l + 3 < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (sa[m1] + sb[z - m1] < sa[m2] + sb[z - m2])l = m1;
            else r = m2;
        }
        ll ans = 0;
        //在小区间内枚举出峰值
        for (int i = l;i <= r;i++)ans = max(sa[i] + sb[z - i], ans);
        cout << ans << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int __ = 1;
    cin >> __;
    while (__--)
        solve();
    return 0;
}