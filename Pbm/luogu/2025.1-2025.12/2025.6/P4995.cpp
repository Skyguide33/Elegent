//2025/6/4
#include <bits/stdc++.h>
using namespace std;

int h[301], hs[301];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> h[i];
  sort(h+1, h+n+1);
  int l = 0, r = n, i = 0;
  while(l < r) {
    hs[i++] = h[l++];
    hs[i++] = h[r--];
  }
  if(l == r) hs[i] = h[l];
  long long ans = 0;
  for(int i = 1; i <= n; ++i) {
    int d = hs[i] - hs[i-1];
    ans += d * d;
  }
  cout << ans << endl;
  return 0;
}