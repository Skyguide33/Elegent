//2026/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[20005];
int head[205], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[205], low[205], tot;
int stk[205], instk[205], top;
int scc[205], cnt;

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

int a[101], b[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i];
    if(a[i] > b[i]) swap(a[i], b[i]);
  }
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i] < a[j] && b[i] > a[j] && b[i] < b[j]) {
        addedge(i, j+m);
        addedge(j, i+m);
        addedge(i+m, j);
        addedge(j+m, i);
      }
    }
  }
  for(int i = 1; i <= 2*m; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  string ans;
  bool flag = 1;
  for(int i = 1; i <= m; ++i) {
    if(scc[i] > scc[i+m]) ans += 'o';
    else if(scc[i] < scc[i+m]) ans += 'i';
    else {
      flag = 0;
      break;
    }
  }
  if(flag) cout << ans << endl;
  else cout << "Impossible" << endl;
  return 0;
}