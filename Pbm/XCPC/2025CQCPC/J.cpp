//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[400005];
int head[200005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

char c[200005];
int dge[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> c[i];
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
    ++dge[u]; ++dge[v];
  }
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(dge[i] == 1) q.push(i);
  }
  int kep = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    // cout << "u=" << u << endl;
    --dge[u]; 
    ++kep;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if(!dge[v]) continue;
      if(c[v] == c[u]) {
        if(--dge[v] == 1) q.push(v);
      }
    }
  }
  cout << n-kep << endl;
  return 0;
}