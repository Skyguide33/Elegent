//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int n, c, ans = 0, a[1005], b[1005];

bool cmp(int x, int y) { return x > y; }

void dfs(int now, int bgn) {
  ans = max(ans, now);
  for(int i = bgn; i <= n; i++) {
    int next = now + a[i], next2 = now+b[n]-b[i-1];
    if(next > c) continue;
    else if(next2 <= c) {
      dfs(next2, n+1);
    } else dfs(next, i+1);
  }
  return;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> c;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1, cmp);
  for(int i = 1; i <= n; i++) b[i] = a[i]+b[i-1];
  dfs(0, 1);
  cout << ans << endl;
  return 0;
}