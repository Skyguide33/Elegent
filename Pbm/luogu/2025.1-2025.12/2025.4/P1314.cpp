//2025/4/9
#include <bits/stdc++.h>
using namespace std;

long long n, m, s, w[200005], v[200005], isL[200005], isR[200005];
struct lr { int l, r; } a[200005];


long long gety(long long W) {
  memset(isL, 0, sizeof(isL));
  memset(isR, 0, sizeof(isR));
  long long L, R, res = -s;
  for(int i = 1; i <= n; i++) {
    if(w[i] >= W) {
      isL[i] = 1;
      isR[i] = v[i];
    }
    isL[i] += isL[i-1];
    isR[i] += isR[i-1];
  }
  for(int i = 1; i <= m; i++) {
    L = isL[a[i].r] - isL[a[i].l-1];
    R = isR[a[i].r] - isR[a[i].l-1];
    res += L*R;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> s;
  long long minW = 1, maxW = 1, midW = minW + (maxW-minW) / 2;
  for(int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    maxW = max(maxW, w[i]);
  }
  for(int i = 1; i <= m; i++) cin >> a[i].l >> a[i].r;
  long long pre, now = 1e18, ans = 1e18;
  maxW++;
  while(minW < maxW) {
    now = gety(midW);
    ans = min(ans, abs(now));
    if(now <= 0) maxW = midW;
    else minW = midW + 1;
    midW = minW + (maxW-minW) / 2; 
  }
  cout << ans << endl;
  return 0;
}