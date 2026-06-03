//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1, 0);
  int maxidx = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[maxidx] < a[i] || (a[maxidx] == a[i] && i == n)) maxidx = i;
  }
  if(maxidx == 1) cout << 1ll*a[maxidx]*(n-1)+a[n] << endl;
  else if(maxidx == n) cout << 1ll*a[maxidx]*(n-1)+a[1] << endl;
  else cout << 1ll*a[maxidx]*(n-2)+a[1]+a[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}