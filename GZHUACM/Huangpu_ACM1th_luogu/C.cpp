//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge {int v, nxt; } e[400005];
int ecnt, head[200005];

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

set<int> p[200005], st[100005];
int d[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, s, t; cin >> n >> m >> s >> t;
  for(int i = 1; i <= m; ++i) {
    int k; cin >> k;
    for(int j = 1; j <= k; ++j) {
      int tt; cin >> tt;
      p[tt].insert(i); 
      st[i].insert(tt);
    }
  }
  fill(d+1, d+m+1, INT_MAX>>1);
  queue<int> q;
  for(int x: p[s]) {
    q.push(x);
    d[x] = 1;
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    if(p[t].contains(u)) {
      cout << d[u] << endl;
      return 0;
    }
    for(int x: st[u]) {
      for(int ss: p[x]) {
        if(d[ss] > d[u]+1) {
          d[ss] = d[u]+1;
          q.push(ss);
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}