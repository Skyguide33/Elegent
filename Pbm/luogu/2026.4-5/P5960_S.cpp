//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[5005];
int head[5005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int d[5005], n;

bool spfa(int src) {
  vector<int> vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 1; i <= n; ++i) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d[v] > d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] == n+1) return 0;
        if(!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int x1, x2, w; cin >> x1 >> x2 >> w;
    addedge(x2, x1, w);
  }
  if(spfa(1)) {
    for(int i = 1; i <= n; ++i) {
      cout << d[i] << ' ';
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}