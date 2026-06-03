//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, tt; cin >> n;
  vector<int> b(n*2+5);
  for(int i = 1; i <= 2*n; ++i) cin >> tt, ++b[tt];
  int cnta = 0, cntb = 0, ans = 0;
  for(int i = 1; i <= 2*n; ++i) {
    if(!b[i]) continue;
    if(b[i]%2 == 0) {
      if(b[i]%4 == 0) {
        cnta += b[i]/2+1;
        cntb += b[i]/2-1;
      } else {
        cnta += b[i]/2;
        cntb += b[i]/2;
      }
      ans += 2;
    }
    if(cnta > cntb) swap(cnta, cntb);
  }
  for(int i = 1; i <= 2*n; ++i) {
    if(!b[i]) continue;
    if(b[i]%2) {
      cnta += b[i]/2+1;
      cntb += b[i]/2;
      ++ans;
    }
    if(cnta > cntb) swap(cnta, cntb);
  }
  // cout << cnta << ' ' << cntb << endl;
  cout << ans-cntb+cnta << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}