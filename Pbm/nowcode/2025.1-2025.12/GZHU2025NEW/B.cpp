//2025/12/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Pin { 
  int id, val, num; 
  bool operator < (const Pin &B) const {
    if(fabs(1.*val/num-1.*B.val/B.num) < 1e-8) {
    return num < B.num;
    }
    return 1.*val/num < 1.*B.val/B.num;
  }
} b[2005][2005];

int ed[2005], idx[2005];

int a[2005], v[2005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  int tt;
  for(int i = 1; i <= n; ++i) cin >> tt, ++a[tt];
  for(int i = 1; i <= m; ++i) cin >> v[i];
  for(int i = 1; i <= m; ++i) {
    int num = 0, cnt = 0;
    for(int j = 1; j <= a[i]; ++j) {
      ++cnt;
      num = (int(log2(j+1))-int(log2(j)))*v[i];
      if(num) {
        b[i][++ed[i]] = {i, num, cnt};
        num = 0; cnt = 0;
      }
    }
  }
  priority_queue<Pin> q;
  for(int i = 1; i <= m; ++i) {
    if(ed[i]) q.push(b[i][++idx[i]]);
  }
  ll ans = 0;
  while(k && !q.empty()) {
    auto [id, val, num] = q.top(); q.pop();
    if(k >= num) {
      ans += val;
      k -= num;
      if(idx[id] < ed[id]) q.push(b[id][++idx[id]]);
    }
  }
  cout << ans << endl;
  return 0;
}