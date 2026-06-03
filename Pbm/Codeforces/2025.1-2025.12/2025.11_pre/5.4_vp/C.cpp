//2025/5/4
#include <bits/stdc++.h>
using namespace std;

struct shop{ long long a, b; } s[100005];

bool cmp(shop x, shop y) { return x.a < y.a; }

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  long long t; cin >> t;
  while(t--) {
    long long n; cin >> n;
    for(long long i = 1; i <= n; ++i) cin >> s[i].a >> s[i].b;
    long long l = 1, r = n;
    sort(s+1, s+n+1, cmp);
    long long ans = 0;
    while(l < r) {
      if(!s[l].b) ++l;
      if(!s[r].b) --r;
      if(l >= r) break;
      ans += s[r].a - s[l].a;
      --s[l].b; --s[r].b;
    }
    cout << ans << endl;
  }
  return 0;
}