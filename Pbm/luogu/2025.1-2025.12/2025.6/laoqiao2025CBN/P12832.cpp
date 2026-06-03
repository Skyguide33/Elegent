//2025/6/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, k; cin >> n >> k;
  ll now = (n+1-(k%n))%n;
  if(n % 2 == 0) {
    if(now % 2 == 0) cout << -1 << endl;
    else cout << (now-1) / 2 << endl;
  } else {
    if(now % 2 == 0) cout << (n+now) / 2  << endl;
    else cout << (now-1) / 2 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T; cin >> T;
  while(T--) solve();
  return 0;
}