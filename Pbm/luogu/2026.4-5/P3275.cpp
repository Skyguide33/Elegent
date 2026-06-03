//2026/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005

struct Edge { int v, w, nxt; } e[3*N];
int head[N], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt;
vector<int> st[N];

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u; instk[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
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
      st[cnt].push_back(v);
    } while(v != u);
  }
}

int idg[N], dp[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= k; ++i) {
    int x, a, b; cin >> x >> a >> b;
    if(x == 1) {
      addedge(a, b, 0);
      addedge(b, a, 0);
    } else if(x == 2) addedge(a, b, 1);
    else if(x == 3) addedge(b, a, 0);
    else if(x == 4) addedge(b, a, 1);
    else addedge(a, b, 0);
  } 
  fill(dp+1, dp+n+1, 1);
  for(int i = 1; i <= n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  for(int u = 1; u <= n; ++u) {
    int su = scc[u];
    for(int i = head[u]; i; i = e[i].nxt) {
      int sv = scc[e[i].v];
      if(su != sv) ++idg[sv];
    }
  }
  queue<int> q;
  for(int i = 1; i <= cnt; ++i) {
    if(idg[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    int su = q.front(); q.pop();
    for(int u: st[su]) {
      for(int i = head[u]; i; i = e[i].nxt) {
        int sv = scc[e[i].v], w = e[i].w;
        if(su != sv) {
          dp[sv] = max(dp[sv], dp[su]+w);
          if(--idg[sv] == 0) q.push(sv);
        } else if(w) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 1; i <= cnt; ++i) {
    ans += 1ll*st[i].size()*dp[i];
  }
  cout << ans << endl;
  return 0;
}