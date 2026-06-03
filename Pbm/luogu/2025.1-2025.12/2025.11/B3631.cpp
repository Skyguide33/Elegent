//2025/11/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    int op, x, y; cin >> op >> x;
    if(op == 1) {
      cin >> y;
      int t = a[x];
      a[x] = y;
      a[y] = t;
    } else if(op == 2) cout << a[x] << endl;
    else {
      int t = a[x];
      a[x] = a[t];
      a[t] = 0;
    }
  }
  return 0;
}