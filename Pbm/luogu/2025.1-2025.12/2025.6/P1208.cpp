//2025/6/4
#include <bits/stdc++.h>
using namespace std;

struct seller {
  int p, a;
} s[5005];

bool cmp(seller x, seller y) { return x.p < y.p; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> s[i].p >> s[i].a;
  }
  sort(s+1, s+m+1, cmp);
  int i = 1, ans = 0;
  while(n) {
    int sold = min(n, s[i].a);
    ans += sold * s[i].p;
    n -= sold;
    ++i;
  }
  cout << ans << endl;
  return 0;
}