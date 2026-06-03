//2025/6/14
#include <bits/stdc++.h>
using namespace std;

int a[101], v[101], n;

int gettk(int bgn) {
  memset(v, 0, sizeof(v));
  int cnt = 1, res = 0, r = n;
  for(int i = bgn;; ++i, ++cnt) {
    if(i % n == 0) i = 0;
    if(cnt > n || r == 0) break;
    if(v[i]) --cnt;
    else if(a[i] == cnt) {
      res += cnt;
      v[i] = 1;
      cnt = 0;
      --r;
    } 
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int res = gettk(i);
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}