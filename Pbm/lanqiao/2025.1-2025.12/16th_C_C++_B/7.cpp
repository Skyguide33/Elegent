//2026/4/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[2005];
int head[1005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int w[1005], dge[1005], fa[1005];

void dfs(int u) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != fa[u]) {
      fa[v] = u;
      dfs(v);
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  vector<set<int>> a(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> w[i]; 
    a[i].insert(0);
  }
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
    ++dge[u]; ++dge[v];
  }
  dfs(1);
  priority_queue<int> q;
  for(int i = 2; i <= n; ++i) {
    if(dge[i] == 1) {
      a[i].insert(w[i]);
      q.push(i);
    }
  }
  while(q.top() != 1) {
    int u = q.top(); q.pop();
    set<int> tmp;
    for(int x: a[fa[u]]) {
      for(int y: a[u]) {
        if(x+y > w[fa[u]]) break;
        tmp.insert(x+y);
      }
    }
    for(int x: tmp) a[fa[u]].insert(x);
    if(--dge[fa[u]] == 1) q.push(fa[u]);
  }
  // for(int i = 1; i <= n; ++i) {
  //   cout << i << ": ";
  //   for(int x: a[i]) cout << x << ' ';
  //   cout << endl;
  // }
  cout << *a[1].rbegin() << endl;
  return 0; 
}