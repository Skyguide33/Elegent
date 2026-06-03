// 测试链接 : https://www.luogu.com.cn/problem/P3265
//标准线性基可用高斯消元
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1e5;
const double sml = 1e-5;
int n, m;

struct node {
    double a[505];
    int w;
    bool operator<(const node& t)const {
        return w < t.w;
    }
}z[505];
int base[505];
int ans = 0;
int cnt = 0;
void insert(int i) {
    for (int j = 1;j <= m;j++) {
        if (abs(z[i].a[j]) > sml) {
            if (base[j] == 0) {
                base[j] = i;
                cnt++;
                ans += z[i].w;
                break;
            }
            double x = z[i].a[j] / z[base[j]].a[j];
            for (int k = j;k <= m;k++)
                z[i].a[k] -= x * z[base[j]].a[k];
        }
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> z[i].a[j];
        }
    }
    for (int i = 1;i <= n;i++)cin >> z[i].w;
    sort(z + 1, z + 1 + n);
    for (int i = 1;i <= n;i++)insert(i);
    cout << cnt << ' ' << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}