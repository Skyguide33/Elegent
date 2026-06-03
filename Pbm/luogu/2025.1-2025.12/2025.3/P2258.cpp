//2025/3/26 retry
#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, a[17][17], rs[17], cs[17], lr[17][17], ud[17], cnt, ans;

void init() {
  for(int i = 2; i <= cnt; i++) {
    ud[i] = 0;
    for(int j = 1; j < m; j++) {
      ud[i] += abs(a[rs[i]][j]-a[rs[i-1]][j]);
    }
  }
  for(int i = 1; i < cnt; i++) {
    for(int j = i+1; j <= cnt; j++) {
      
    }
  }
}

void dp() {
  init();
}

void dfs(int ft) {
  if(cnt == r) {
    dp();
    return;
  }
  for(int i = ft; i < n; i++) {
    cnt++;
    rs[cnt] = i;
    dfs(i+1);
    cnt--;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> r >> c;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) cin >> a[i][j];
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}