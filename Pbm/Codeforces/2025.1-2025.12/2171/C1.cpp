//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n; cin >> n;
  int cnta = 0, cntb = 0;
  for(int i = 1; i <= n; ++i) cin >> a[i], cnta += a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i], cntb += b[i];
  if((cnta-cntb)%2 == 0) {
    cout << "Tie" << endl;
    return;
  }
  for(int i = n; i >= 1; --i) {
    if(a[i] != b[i]) {
      if(i%2) cout << "Ajisai" << endl;
      else cout << "Mai" << endl;
      break;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}