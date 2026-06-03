//2026/3/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[200005];
int head[200005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int n, ans = INT_MAX>>1, vis[200005], pre[200005];

void bfs(int s) {
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int t; cin >> t;
    addedge(i, t);
  }

  return 0;
}