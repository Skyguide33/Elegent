//2025/6/4
#include <bits/stdc++.h>
using namespace std;

int p[30005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int w, n; cin >> w >> n;
  for(int i = 1; i <= n; ++i) cin >> p[i];
  sort(p+1, p+n+1);
  int l = 1, r = n, ans = 0;
  while(l < r) {
    if(p[l]+p[r] <= w) {
      ++ans; ++l; --r;
    } else {
      ++ans; --r;
    }
  }
  if(l == r) ++ans;
  cout << ans << endl;
  return 0;
}