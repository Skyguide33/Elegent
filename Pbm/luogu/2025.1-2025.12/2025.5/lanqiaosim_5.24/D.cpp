//2025/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, m; cin >> n >> m;
  long long e[n+1][n+1], d[n+1];
  memset(e, 127, sizeof(e));
  for(ll i = 1; i <= m; ++i) {
    ll a, b, c; cin >> a >> b >> c;
    e[a][b] = e[b][a] = c;
  }
  ll seq[n+1];
  for(ll i = 1; i <= n; ++i) seq[i] = i;
  ll pmt = 1, ans = INF;
  while(pmt) {
    memset(d, 0, sizeof(d));
    ll res = 0;
    for(ll i = 1; i <= n; ++i) {
      ll k = 0, sum = 0;
      d[seq[i]] = 1;
      for(ll j = 1; j <= n; ++j) {
        if(e[seq[i]][seq[j]] <= 1e9 && !d[seq[j]]) {
          ++k; sum += e[seq[i]][seq[j]];
        }
      }
      res += k * sum;
    }
    ans = min(ans, res);
    pmt = next_permutation(seq+1, seq+n+1);
  }
  cout << ans << endl;
  return 0;
}