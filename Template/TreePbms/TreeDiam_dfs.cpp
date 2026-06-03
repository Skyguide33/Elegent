//2025/9/4 树的直径
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 100005;

int n;
struct edge { int to, w; };
vector<edge> e[N];
int dist[N];

void dfs(int u, int fa, int d) {
  dist[u] = d;
  for(auto& x: e[u]) {
    if(x.to == fa) continue;
    dfs(x.to, u, d+x.w); 
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v, w; cin >> u >> v >> w;
    e[u].push_back({v, w}); e[v].push_back({u, w});
  }
  dfs(1, -1, 0);
  int s1 = 1, d = 0;
  for(int i = 1; i <= n; ++i) {
    if(dist[i] > d) { 
      s1 = i;
      d = dist[i];
    }
  }
  dfs(s1, -1, 0);
  int s2 = s1; d = 0;
  for(int i = 1; i <= n; ++i) {
    if(dist[i] > d) { 
      s2 = i;
      d = dist[i];
    }
  }
  cout << "Diam: "<< d <<" (" << s1 << "->" << s2 << ")" << endl;
  return 0;
}