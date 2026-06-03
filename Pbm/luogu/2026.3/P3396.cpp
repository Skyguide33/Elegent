//2026/3/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int v[150005], b[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> v[i];
    for(int j = 1; j <= 1001; ++j) b[j][i%j] += v[i];
  }
  while(m--) {
    char cmd; cin >> cmd;
    int x, y; cin >> x >> y;
    if(cmd == 'A') cout << b[min(1001, x)][y] << endl;
    else {
      int old = v[x]; v[x] = y;
      for(int mod = 1; mod <= 1001; ++mod) b[mod][x%mod] += y-old;
    }
  }
  return 0;
}