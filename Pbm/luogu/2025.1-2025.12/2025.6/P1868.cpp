//2025/6/6
#include <bits/stdc++.h>
using namespace std;

struct area{
  int l, r;
} a[150005];

int dp[3000005];

bool cmp(area x, area y) {
  if(x.r != y.r) return x.r < y.r;
  return x.l < y.l;
}

int n;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a+1, a+n+1, cmp);
  a[0] = {-1, -1};
  for(int i = 1; i <= n; ++i) {
    int pre = a[i-1].r, now = a[i].r;
    for(int j = pre+1; j <= now; ++j) dp[j] = dp[pre];
    dp[now] = max(dp[now], dp[a[i].l-1]+a[i].r-a[i].l+1);
  }
  cout << dp[a[n].r] << endl;
  return 0;
}