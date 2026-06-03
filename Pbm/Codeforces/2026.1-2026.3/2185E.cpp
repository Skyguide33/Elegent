//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005], mn[200005], mx[200005], sum[200005];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i];
  sort(b+1, b+m+1);
  b[0] = INT_MIN>>1; b[m+1] = INT_MAX>>1;
  int now = 0;
  for(int i = 1; i <= k; ++i) {
    char ch; cin >> ch;
    now += (ch =='L'? -1: 1);
    mn[i] = max(mn[i-1], -now);
    mx[i] = max(mx[i-1], now);
  }
  fill(sum+1, sum+k+1, 0);
  for(int i = 1; i <= n; ++i) {
    int pos = upper_bound(b, b+m+2, a[i])-b;
    ++sum[min(upper_bound(mn+1, mn+k+1, a[i]-b[pos-1]-1)-mn, 
              upper_bound(mx+1, mx+k+1, b[pos]-1-a[i])-mx)];
  }
  for(int i = 1; i <= k; ++i) {
    sum[i] += sum[i-1];
    cout << n-sum[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}