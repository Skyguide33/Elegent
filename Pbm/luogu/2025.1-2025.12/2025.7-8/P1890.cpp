//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int q[1001][1001];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, l, r; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> q[i][i];
    for(int j = 1; j <= i; ++j) {
      q[j][i] = __gcd(q[j][i-1], q[i][i]);
    }
  }
  while(m--) {
    cin >> l >> r;
    cout << q[l][r] << endl;
  }
  return 0;
}