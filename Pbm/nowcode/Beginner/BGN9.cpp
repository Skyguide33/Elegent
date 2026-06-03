//2026/3/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005];

void solve() {
  int n; cin >> n;
  ll avg = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    avg += a[i];
  }
  if(n == 1) {
    cout << "YES" << endl;
    return;
  }
  if(avg%n) {
    cout << "NO" << endl;
    return;
  }
  avg /= n;
  for(int i = 1; i <= n-2; ++i) {
    ll dist = a[i]-avg;
    a[i] -= dist;
    a[i+2] += dist;
  }
  if(a[n-1] == avg && a[n] == avg) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}