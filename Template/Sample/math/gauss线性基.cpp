#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const int N = 1e5 + 5;

const int BIT = 50;

ll a[N], base[N];
bool zero = false;
int sz = 1;
void gauss(int n) {
    for (int i = BIT;i >= 0;i--) {
        for (int j = sz;j <= n;j++) {
            if ((base[j] >> i) & 1) {
                swap(base[sz], base[j]);
                break;
            }
        }
        if (base[sz] & (1LL << i)) {//找的到主元
            for (int j = 1;j <= n;j++)
                if (sz != j && (base[j] & (1LL << i)))
                    base[j] ^= base[sz];
            sz++;
        }
    }
    sz--;
    zero = (sz != n);
}

void print(int n) {
    for (int i = 1;i <= n;i++)cout << base[i] << " \n"[i == n];
}
//第K小数
ll query(ll k) {
    if (zero) {
        k--;
        if (k == 0)return 0;
    }

    if (k >= (1LL << sz))return -1;
    ll res = 0;
    for (int i = 0;i < sz;i++)
        if (k & (1LL << i))res ^= base[i + 1];
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        base[i] = a[i];
    }
    gauss(n);

    //  最大值
    // ll mx = 0;
    // for (int i = sz;i >= 0;i--)
    //     mx ^= base[i];
    // cout << mx << '\n';
    reverse(base + 1, base + sz + 1);
    int m;
    cin >> m;
    ll k;
    while (m--) {
        cin >> k;
        cout << query(k) << '\n';
    }
}

signed main() {

    solve();

    return 0;
}