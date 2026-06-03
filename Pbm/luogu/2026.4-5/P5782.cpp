//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 40005

struct Edge { int v, nxt; } e[N];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt;

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u; instk[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(instk[v]) low[u] = min(low[u], dfn[v]);
  }
  if(low[u] == dfn[u]) {
    ++cnt;
    int v;
    do {
      v = stk[top--]; instk[v] = 0;
      scc[v] = cnt;
    } while(v != u);
  }
}

int get(int x) {
  if(x%2) return x+1;
  return x-1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int k = 1; k <= m; ++k) {
    int a, b; cin >> a >> b;
    addedge(a, get(b));
    addedge(b, get(a));
  }
  for(int i = 1; i <= 2*n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  for(int i = 2; i <= 2*n; i += 2) {
    if(scc[i] == scc[i-1]) {
      cout << "NIE" << endl;
      return 0;
    }
  }
  for(int i = 2; i <= 2*n; i += 2) {
    if(scc[i-1] < scc[i]) cout << i-1 << endl;
    else cout << i << endl;
  }
  return 0;
}