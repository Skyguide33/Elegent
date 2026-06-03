//2026/3/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge{ int v, nxt; } e[1000005];
int head[500005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int s[500005];

void init_set(int n) {
  for(int i = 1; i <= n; ++i) s[i] = i;
}

int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

struct Query { int num, v, nxt; } query[1000005];
int q_head[500005], q_cnt;

void add_query(int num, int u, int v) {
  query[++q_cnt] = {num, v, q_head[u]};
  q_head[u] = q_cnt;
}

int vis[500005], ans[500005];

void tarjan(int u) {
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!vis[v]) {
      tarjan(v);
      s[v] = u;
    }
  }
  for(int i = q_head[u]; i; i = query[i].nxt) 
    if(vis[query[i].v]) 
      ans[query[i].num] = find_set(query[i].v);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, rt; cin >> n >> m >> rt;
  init_set(n);
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    addedge(x, y); addedge(y, x);
  }
  for(int i = 1; i <= m; ++i) {
    int a, b; cin >> a >> b;
    add_query(i, a, b); add_query(i, b, a);
  }
  tarjan(rt);
  for(int i = 1; i <= m; ++i) cout << ans[i] << endl;
  return 0;
}