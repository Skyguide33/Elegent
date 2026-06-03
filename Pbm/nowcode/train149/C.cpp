//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[505], b[505], cnt[500005], dis[500005], sum[500005];

void solve() {
  int n, m; cin >> n >> m;
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  memset(dis, 0x3f, sizeof(dis));
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) {
    dis[a[i]] = 0;
    vector<int> num; 
    queue<int> q; q.push(a[i]);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      ++cnt[u];
      num.push_back(u);
      for(int j = 1; j <= m; ++j) {
        int gd = gcd(u, b[j]);
        if(dis[gd] > 1e9) {
          dis[gd] = dis[u]+1;
          sum[gd] += dis[gd];
          q.push(gd);
        }
      }
    }
    for(int x: num) dis[x] = INT_MAX>>1;
  }
  int ans = INT_MAX>>1;
  for(int i = 1; i <= 500000; ++i) {
    if(cnt[i] == n) ans = min(ans, sum[i]);
  }
  if(ans == INT_MAX>>1) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}