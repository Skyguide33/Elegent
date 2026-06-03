//2026/5/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int S; cin >> S;
  array<int, 8> f;
  for(int i = 1; i <= 7; ++i) cin >> f[i];
  int res = S;
  for(unsigned t = 1; t <= 7; ++t) {
    int sum = 0;
    for(unsigned s = 1; s <= 7; ++s) {
      if(s&t) sum += f[s];
    }
    res = min(res, sum/popcount(t));
  }
  cout << res << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}