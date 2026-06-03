//2025/11/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int l, r; cin >> l >> r;
  --l;
  int la = (l+2)/3, lb = (l+1)/3, lc = l/3;
  int ra = (r+2)/3, rb = (r+1)/3, rc = r/3;
  cout << ra-la << ' ' << rb-lb << ' ' << rc-lc << endl;
  return 0;
}