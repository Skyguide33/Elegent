//2025/4/26
#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 1e9

int c[N], f[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> c[i];
  int minv = INF, id;
  for(int i = n; i >= 1; --i) {
    if(c[i] < minv) {
      minv = c[i]; id = i;
      f[i] = id;
    } else f[i] = id;
  }
  int ans = 0, sum = 0, pre = 0;
  for(int i = 1; i <= n; ++i) {
    i = f[i];
    sum += i - pre;
    ans += sum / c[i];
    sum %= c[i];
    pre = i;
  }
  cout << ans << endl;
  return 0;
}