//2025/9/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 500005;

int fa[N], head[N], cnt, head_query[N], cnt_query, ans[N];
bool vis[N];

struct Edge{ int to, next, num; } e[N<<1], query[N<<1];

void init(int n) {
  for(int i = 0; i <= n; ++i) head[i] = head_query[i] = -1;
  n <<= 1;
  for(int i = 0; i <= n; ++i) e[i].next = query[i].next = -1;
}

void addedge(int u, int v) {
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt++;
}

void add_query(int x, int y, int num) {
  query[cnt_query].to = y;
  query[cnt_query].next = head_query[x];
  query[cnt_query].num = num;
  head_query[x] = cnt_query++;
}

int find_set(int x) {
  return fa[x] == x? x: fa[x] = find_set(fa[x]);
}

void tarjan(int x) {
  vis[x] = true;
  for(int i = head[x]; ~i; i = e[i].next) {
    int y = e[i].to;
    if(!vis[y]) {
      tarjan(y);
      fa[y] = x;
    }
  }
  for(int i = head_query[x]; ~i; i = query[i].next) {
    int y = query[i].to;
    if(vis[y]) ans[query[i].num] = find_set(y);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(vis, 0, sizeof(vis));
  int n, m, root; cin >> n >> m >> root;
  init(n);
  for(int i = 1; i < n; ++i) {
    fa[i] = i;
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  fa[n] = n;
  for(int i = 1; i <= m; ++i) {
    int a, b; cin >> a >> b;
    add_query(a, b, i); add_query(b, a, i);
  }
  tarjan(root);
  for(int i = 1; i <= m; ++i) cout << ans[i] << endl;
  return 0;
}