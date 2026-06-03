//卡特兰数

#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6 + 5;
const int P = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

int fac[N], inv[N];
void init() {
    fac[0] = fac[1] = 1;
    for (int i = 2;i < N;i++) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    inv[N - 1] = qpow(fac[N - 1], P - 2);
    for (int i = N - 2;i >= 0;i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % P;
    }
}

ll C(int n, int m) {
    if (m > n)return 0;
    if (n < 0 || m < 0)return 0;
    return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}
//C(2n,n)-C(2n,n-1);
ll f1(int n) {
    if (!n)return 1ll;
    return (C(n * 2, n) - C(n * 2, n - 1) + P) % P;
}
//C(2n,n)/(n+1);
ll f2(int n) {
    return C(n * 2, n) * qpow(n + 1, P - 2) % P;
}


//递推:

//f(n)=f(n-1)*(4n-2)/(n+1);
ll f3(int n) {
    ll res = 1;
    for (int i = 1;i <= n;i++) {
        res = res * (4 * i - 2) % P * qpow(i + 1, P - 2) % P;
    }
    return res;
}

//Σf(i)*f(n-i-1)  0 1 2 ...n-1
int f[N];
ll f4(int n) {
    f[0] = f[1] = 1;
    for (int i = 2;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            f[i] = (f[i] + 1ll * f[j] * f[i - j - 1] % P) % P;
        }
    }
    return f[n];
}

void solve() {
    int n;
    cin >> n;
    cout << f1(n);
    // cout << f2(n);
    // cout << f3(n);
    // cout << f4(n);
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}