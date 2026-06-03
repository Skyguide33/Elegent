//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int a[n+1], b[n+1];
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  int maxn = -200, ansx = 0, ansy = 0;
  for(int x = 1; x <= n; ++x) {
    for(int y = 1; y <= n; ++y) {
      int tp = 0;
      for(int i = 1; i <= n; ++i) {
        tp += (a[i]-a[x])-(b[i]-b[y]);
      }
      if(tp > maxn) {
        maxn = tp;
        ansx = x; ansy = y;
      }
    }
  }
  cout << ansx << ' ' << ansy << endl;
  return 0;
}