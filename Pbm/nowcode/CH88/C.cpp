//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

pair<int, int> p[100005];

ll b[10000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  b[1] = 1;
  for(int i = 2; i <= n; ++i) {
    b[i] = (3*b[i-1]%MOD-b[i-2]+MOD)%MOD;
  }
  b[0] = 1;
  for(int i = 0; i <= 10; ++i) cout << b[i] << ' ';
  cout << endl;
  for(int i = 1; i <= m; ++i) cin >> p[i].first >> p[i].second;
  sort(p+1, p+m+1);
  for(int i = 2; i <= m; ++i) {
    if(p[i-1].first == p[i].first || p[i-1].second > p[i].second) {
      cout << 0 << endl;
      return 0;
    }
  }
  if(p[m] != make_tuple(n, n)) p[++m] = make_tuple(n, n);
  p[0] = {0, 1};
  ll ans = 1;
  for(int i = 1; i <= m; ++i) {
    cout << p[i].first-p[i-1].first-1 << ' ' << p[i].second-p[i-1].second+1 << ' ' << min(p[i].first-p[i-1].first-1, p[i].second-p[i-1].second+1)+2-(i == 1)-(i == m) << endl;
    ans = ans*b[min(p[i].first-p[i-1].first-1, max(0, p[i].second-max(p[i-1].second, p[i-1].first)+1))+2-(i == 1)-(i == m)]%MOD;
  }
  cout << ans << endl;
  return 0;
}