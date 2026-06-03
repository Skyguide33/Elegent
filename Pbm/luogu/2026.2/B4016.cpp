//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, nxt; } e[200005];
int head[100005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]}; // 若为有向边则删去下两行
  head[v] = cnt;
}

int ans, n;

int dfs(int u, int fa) {
  int d1 = 0, d2 = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v == fa) continue;
    int len = dfs(v, u)+1;
    if(len > d1) d2 = d1, d1 = len;
    else if(len > d2) d2 = len;
  }
  ans = max(ans, d1+d2);
  return d1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}