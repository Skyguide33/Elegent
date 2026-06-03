//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[10005];
int head[101], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[101], low[101], tot;
int stk[101], instk[101], top;
int scc[101], cnt;
int idg[101], odg[101];

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u; instk[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(instk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    while(1) {
      int tt; cin >> tt;
      if(!tt) break;
      addedge(i, tt);
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  if(cnt == 1) {
    cout << 1 << endl << 0 << endl;
  } else {
    for(int u = 1; u <= n; ++u) {
      for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(scc[u] != scc[v]) {
          ++idg[scc[v]];
          ++odg[scc[u]];
        }
      }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= cnt; ++i) {
      if(!idg[i]) ++ans1;
      if(!odg[i]) ++ans2;
    }
    cout << ans1 << endl << max(ans1, ans2) << endl;
  }
  return 0;
}