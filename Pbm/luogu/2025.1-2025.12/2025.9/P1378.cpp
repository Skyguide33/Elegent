//2025/9/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const double PI = 3.14159265358;

int x[7], y[7], n;
bool vis[7];
double res = 0., r[7], x1, y11, x2, y2;

void dfs(int now, int cnt, double sum) {
  if(cnt == n) {
    res = max(res, sum);
    return;
  }
  for(int i = 1; i <= n; ++i) {
    if(vis[i]) continue;
    r[i] = min({x2-x[i], x[i]-x1, y11-y[i], y[i]-y2});
    for(int j = 1; j <= n; ++j) {
      if(vis[j]) {
        r[i] = min(r[i], max(0., hypot(x[i]-x[j], y[i]-y[j])-r[j]));
      }
    }
    vis[i] = 1;
    dfs(i, cnt+1, sum+r[i]*r[i]*PI);
    vis[i] = 0;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  cin >> x1 >> y11 >> x2 >> y2;
  if(x1 > x2) swap(x1, x2);
  if(y11 < y2) swap(y11, y2);
  for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  dfs(0, 0, 0);
  cout << int(round((x2-x1)*(y11-y2)-res)) << endl;
  return 0;
}