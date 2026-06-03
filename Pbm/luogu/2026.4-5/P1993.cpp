//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[10005];
int head[5005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int d[5005], n;

// 求最大解
bool spfa() {
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
        if(cnt[v] >= n) return 0; // 有负环则无解
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
    int op, a, b; cin >> op >> a >> b;
    if(op == 3) {
      addedge(a, b, 0);
      addedge(b, a, 0);
    } else {
      int c; cin >> c;
      if(op == 1) addedge(a, b, -c);   
      else addedge(b, a, c);
    }
  }
  if(spfa()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}