//2025/4/18
#include <bits/stdc++.h>
using namespace std;

int N, a[21];
bool c[21][21], vis[21];
int ans2 = -1, path[21], nodes;
vector<int> ans1;

void dfs(int now, int node_n, int num) {
  bool end = 1;
  for(int i = 1; i <= N; i++) {
    if(!vis[i] && c[now][i]) {
      end = 0;
      vis[i] = 1;
      path[node_n] = i;
      dfs(i, node_n+1, num+a[i]);
      vis[i] = 0;
    }
  }
  if(end && num > ans2) {
    ans2 = num;
    ans1.clear();
    for(int i = 0; i < node_n; i++) ans1.push_back(path[i]);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> a[i];
  for(int i = 1; i < N; i++) {
    for(int j = i+1; j <= N; j++) cin >> c[i][j]; 
  }
  for(int i = 1; i <= N; i++) c[0][i] = 1;
  dfs(0, 0, 0);
  for(auto& x: ans1) cout << x << ' ';
  cout << endl << ans2 << endl;
  return 0;
}