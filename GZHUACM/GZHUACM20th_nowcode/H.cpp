//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
struct Edge { int v, nxt; } e[20005];
int head[10005], ecnt;
 
void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}
 
int ans[10005], n, len, maxn = INT_MAX>>1;
 
int dfs(int u, int fa) {
  int sum = 1, num = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v; 
    if(v == fa) continue;
    int tt = dfs(v, u);
    sum += tt;
    num = max(num, tt);
  }
  num = max(num, n-sum);
  if(num < maxn) {
    maxn = num;
    ans[len=1] = u;
  } else if(num == maxn) {
    ans[++len] = u;
  }
  return sum;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  dfs(1, 0);
  cout << ans[1] << endl;
  cout << "Adachi" << endl;
  return 0;
}