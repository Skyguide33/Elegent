//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int l, r, x; cin >> l >> r >> x;
  if(r/x == l/x) cout << -1 << endl;
  else cout << r/x*x << endl;
  return 0;
}