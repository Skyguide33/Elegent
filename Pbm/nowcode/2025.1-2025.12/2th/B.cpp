//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[500005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  if(n > 60) cout << "NO" << endl;
  else {
    for(int i = 1; i < n; ++i) {
      for(int j = i+1; j <= n; ++j) {
        if((a[i]^a[j]) <= max(a[i], a[j])) {
          cout << "NO" << endl;
          return;
        }
      }
    }
    cout << "YES" << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}