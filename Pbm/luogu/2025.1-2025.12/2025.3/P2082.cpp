//2025/3/24
#include <bits/stdc++.h>
using namespace std;

struct line{
  long long a, b;
}e[100005];

inline bool cmp(line x, line y) { return x.a < y.a; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(register int i = 1; i <= n; i++) cin >>  e[i].a >> e[i].b;
  sort(e+1, e+n+1, cmp);
  long long begin = 0, end =-1, ans = 0;
  for(int i = 1; i <= n; i++) {
    if(end >= e[i].a-1) {
      end = max(end, e[i].b);
    } else {
      ans += end-begin+1;
      begin = e[i].a; end = e[i].b;
    }
  }
  ans += end-begin+1;
  cout << ans << endl;
  //cout << ans << ndl;
  return 0;
}