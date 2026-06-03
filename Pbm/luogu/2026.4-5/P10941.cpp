//2026/5/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[75];
int head[25], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int rr[25], a[25];

bool spfa() {
  vector<int> d(25, INT_MAX>>1), vis(25, 1), cnt(25);
  queue<int> q;
  for(int i = 0; i <= 24; ++i) q.push(i);
  d[0] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d[v] > d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= 25) return 0;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 1;
}

void solve() {
  for(int i = 1; i <= 24; ++i) {
    cin >> rr[i];
    a[i] = 0;
  }
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    ++a[tt+1];
  } 
  int l = 0, r = n+1;
  while(l < r) {
    int mid = (l+r)>>1;
    ecnt = 0;
    for(int i = 0; i <= 24; ++i) head[i] = 0;
    for(int i = 1; i <= 24; ++i) {
      addedge(i, i-1, 0);
      addedge(i-1, i, a[i]);
      if(i < 8) addedge(i, i+16, mid-rr[i]);
      else addedge(i, i-8, -rr[i]);
    }
    addedge(24, 0, -mid);
    addedge(0, 24, mid);
    if(spfa()) r = mid;
    else l = mid+1;
  }
  if(l == n+1) cout << "No Solution" << endl;
  else cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}