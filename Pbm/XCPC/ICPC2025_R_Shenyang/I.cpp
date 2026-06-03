//2026/3/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt[415], ac[415][14];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(ac, -1, sizeof(ac));
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    if(ac[a][b] == -1) {
      ac[a][b] = c;
      if(c < 240 || cnt[a] < 3) cout << b << endl;
      else cout << 0 << endl;
      ++cnt[a];
    } else cout << 0 << endl;
  }
  return 0;
}