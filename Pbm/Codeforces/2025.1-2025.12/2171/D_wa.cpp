//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> p[i];
  int ridx = n, lidx = 1;
  for(int i = n-1; i >= 1; --i) {
    if(p[i] < p[n]) ridx = i;
  }
  for(int i = 2; i <= n; ++i) {
    if(p[1] < p[i]) lidx = i;
  }
  if(lidx > ridx) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}