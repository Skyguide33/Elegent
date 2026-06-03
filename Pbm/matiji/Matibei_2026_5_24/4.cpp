//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10005], minp[10005], maxp[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxp[i] = n+1;
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = i-1; j >= 1; --j) {
      if(a[j] < a[i]) {
        minp[i] = j;
        break;
      }
    }
    for(int j = i+1; j <= n; ++j) {
      if(a[j] > a[i]) {
        maxp[i] = j;
        break;
      }
    }
  }
  while(q--) {
    int l, r; cin >> l >> r;
    bool flag = 0;
    for(int i = l; i <= r; ++i) {
      if(minp[i] >= l && maxp[i] <= r) {
        flag = 1;
        break;
      }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}