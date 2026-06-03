//2025/9/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[18][100005], n;

void init() {
  for(int i = 1; i <= log2(n); ++i) {
    for(int j = 1; j <= n; ++j) {
      s[i][j] = s[i-1][j];
      if(j+(1<<i) <= n) s[i][j] = min(s[i][j], s[i-1][j+(1<<(i-1))]);
      // cout << s[i][j] << ' ';
    }
    // cout << endl;
  }
}

int query(int l, int r) {
  int len = r-l+1;
  int i = log2(len);
  return min(s[i][l], s[i][r-(1<<i)+1]);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> s[0][i];
  init();
  while(m--) {
    int l, r; cin >> l >> r;
    cout << query(l, r) << ' ';
  }
  cout << endl;
  return 0;
}