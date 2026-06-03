//逆康托展开
#include <bits/stdc++.h>

using namespace std;
#define ll long long
// #define int ll
#define PII pair<int, int>
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll inf = 2e18 + 10;
const int N = 1e5 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

struct tree {
    int l, r, sum;
}tr[N << 2];

//阶乘进制表
// 1    2   ... n-2 n-1 n 
// n-1! n-2! ... 2! 1! 0!
ll a[N];
ll n, m;

void up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    tr[u] = { l,r,1 };
    if (l == r)return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    up(u);
}

void add(int u, int x, int v) {
    if (tr[u].l == tr[u].r) {
        tr[u].sum += v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)add(u << 1, x, v);
    else add(u << 1 | 1, x, v);
    up(u);
}

int qry(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid)res += qry(u << 1, l, r);
    if (r > mid)res += qry(u << 1 | 1, l, r);
    return res;
}

// ll fac[N];
// void init() {
// 	fac[0] = 1;
// 	for (int i = 1;i < N;i++) {
// 		fac[i] = fac[i - 1] * i % P;
// 	}
// }

void solve() {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        add(1, x, -1);
        a[i] = qry(1, 1, x);
    }

    // for (int i = 1;i <= n;i++)
    // 	cout << a[i] << " \n"[i == n];

    a[n] += m;

    //进位
    for (int i = 1;i < n;i++) {
        a[n - i] += a[n - i + 1] / i;
        a[n - i + 1] %= i;
    }

    // for (int i = 1;i <= n;i++)
    // 	cout << a[i] << " \n"[i == n];


    build(1, 1, n);
    for (int i = 1;i <= n;i++) {
        int l = 0, r = n + 1, mid;
        while (l + 1 < r) {
            mid = l + r >> 1;
            if (qry(1, 1, mid) > a[i])
                r = mid;
            else
                l = mid;
        }
        cout << r << ' ';
        add(1, r, -1);
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // init();
    int TT = 1;
    // cin >> TT;
    while (TT--)
        solve();
    return 0;
}