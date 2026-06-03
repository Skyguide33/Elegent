//2025/11/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[5005], b[5005], c[5005], n, d;
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> d;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  ll ans = 0, res;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(a[j] >= b[i]) {
        if(a[j] <= b[i]+d) c[j] = a[j];
        else c[j] = b[i]+d;
      } else c[j] = b[i];
    }
    res = 0;
    for(int i = 2; i <= n; ++i) res += abs(c[i]-c[i-1]);
    ans = max(ans, res);
    for(int j = 1; j <= n; ++j) {
      if(a[j] >= b[i]-d) {
        if(a[j] <= b[i]) c[j] = a[j];
        else c[j] = b[i];
      } else c[j] = b[i]-d;
    }
    res = 0;
    for(int i = 2; i <= n; ++i) res += abs(c[i]-c[i-1]);
    ans = max(ans, res);
  }
  cout << wa << ' ' << wb << ' ' << te << endl;
  cout << ans << endl;
  return 0;
}