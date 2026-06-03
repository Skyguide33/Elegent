//2025/12/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n; cin >> n;
  int t = sqrt(n);
  int ans = 0;
  for(int i = 1; i <= t; ++i) {
    if(1ll*i*i%3 == 0) ++ans;
  }
  cout << t/3 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}