//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dis[200005], tdis[200005], seq[200005];

vector<int> e[200005];

void addedge(int u, int v) {
  e[u].push_back(v);
  e[v].push_back(u);
}

bool cmp(int x, int y) {
  return e[x].size() > e[y].size();
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    dis[i] = INT_MAX>>1;
    seq[i] = i;
  }
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  sort(seq+1, seq+n+1, cmp);
  queue<int> q;
  int l = 1, r = 1;
  while(r <= n) {
    while(r <= n && e[seq[l]].size() == e[seq[r+1]].size()) ++r;
    for(int i = 1; i <= n; ++i) tdis[i] = INT_MAX>>1;
    for(int i = l; i <= r; ++i) {
      q.push(seq[i]);
      tdis[seq[i]] = 0;
    }
    size_t pri = e[seq[l]].size();
    while(!q.empty()) {
      int now = q.front(); q.pop();
      int ndis = tdis[now]+1;
      for(int v: e[now]) {
        if(ndis >= tdis[v]) continue;
        tdis[v] = ndis;
        if(e[v].size() < pri) dis[v] = min(dis[v], tdis[v]); 
        q.push(v);
      }
    }
    ++r; l = r;
  }
  for(int i = 1; i <= n; ++i) {
    if(dis[i] == INT_MAX>>1) cout << -1 << ' ';
    else cout << dis[i] << ' ';
  }
  cout << endl;
  return 0;
}