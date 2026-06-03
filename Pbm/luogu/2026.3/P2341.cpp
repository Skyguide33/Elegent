//2025/3/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
#define N 10005

struct Edge { int v, nxt; } e[50005];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
int outdge[N];

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
  if(dfn[u] == low[u]) {
    int v; ++cnt;
    do {
      v = stk[top--]; instk[v] = 0;
      scc[v] = cnt;
      ++siz[cnt];
    } while(u != v);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int a, b; cin >> a >> b;
    addedge(a, b);
  }
  for(int i = 1; i <= n; ++i) 
    if(!dfn[i]) tarjan(i);
  for(int u = 1; u <= n; ++u) {
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if(scc[u] != scc[v]) ++outdge[scc[u]];
    }
  }
  int ans = 0, zeros = 0;
  for(int i = 1; i <= cnt; ++i) {
    if(outdge[i] == 0) {
      ++zeros; ans = siz[i];
    }
  }
  if(zeros > 1) cout << 0 << endl;
  else cout << ans << endl;
}