//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[5005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    int upcnt = 0, lwcnt = 0;
    for(int j = i+1; j <= n; ++j) {
      if(a[j] > a[i]) ++upcnt;
      else if(a[j] < a[i]) ++lwcnt;
    }
    cout << max(upcnt, lwcnt) << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}