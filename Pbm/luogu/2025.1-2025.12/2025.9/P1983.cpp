//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int in[1005], vis[1005], dir[1005][1005];
vector<int> e[1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(m--) {
    memset(vis, 0, sizeof(vis));
    int num, src, des; cin >> num >> src;
    vis[src] = 1;
    num -= 2;
    while(num--) {
      int t; cin >> t;
      vis[t] = 1;
    }
    cin >> des;
    vis[des] = 1;
    for(int i = src+1; i < des; ++i) {
      if(!vis[i]) {
        for(int j = src; j <= des; ++j) {
          if(vis[j] && !dir[i][j]) {
            dir[i][j] = 1; ++in[j];
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(dir[i][j]) e[i].push_back(j);
    } 
  }
  int ans = 0;
  queue<pair<int, int>> q;
  for(int i = 1; i <= n; ++i) {
    if(!in[i]) q.push({i, 1});
  }
  while(!q.empty()) {
    auto [now, cnt] = q.front(); q.pop();
    ans = max(ans, cnt);
    for(auto &x: e[now]) {
      if(!--in[x]) q.push({x, cnt+1});
    }
  }
  cout << ans << endl;
  return 0;
}