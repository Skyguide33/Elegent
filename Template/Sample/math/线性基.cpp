#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const int N = 2e5 + 5;

const int BIT = 51;
ll a[60];
ll base[BIT];
bool zero = 0;

bool insert(ll x) {
    for (int i = 50;i >= 0;i--) {
        if (x >> i) {
            if (base[i] == 0) {
                base[i] = x;
                return true;
            }
            x ^= base[i];
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (int i = 1;i <= n;i++)
        if (!insert(a[i]))zero = true;
    ll mx = 0;
    // for (int i = 0;i <= 60;i++) {
    //     if (base[i])cout << base[i] << ' ';
    // }
    for (int i = 50;i >= 0;i--) {
        if ((mx ^ base[i]) > mx)mx ^= base[i];
    }
    cout << mx << '\n';
}


signed main() {
    solve();
    return 0;
}