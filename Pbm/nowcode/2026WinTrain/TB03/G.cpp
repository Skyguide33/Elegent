//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n+1), b(m+1);
  ll asum = 0, bsum = 0;
  for(int i = 1; i <= n; ++i) cin >> a[i], asum += a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i], bsum += b[i];
  if(asum == bsum) cout << 1 << endl;
  else if(asum > bsum) {
    sort(a.begin()+1, a.end());
    int cnt = 0;
    while(asum > bsum) {
      asum -= a[n-cnt];
      ++cnt;
    }
    cout << cnt << endl;
  } else {
    sort(b.begin()+1, b.end());
    int cnt = 0;
    while(bsum > asum) {
      bsum -= b[m-cnt];
      ++cnt;
    }
    cout << cnt << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}