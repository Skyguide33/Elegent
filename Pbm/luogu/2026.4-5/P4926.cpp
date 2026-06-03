//2026/5/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Flag { 
  int o, A, B, k;
} f[1005];

struct Edge { 
  int v, nxt; 
  double w;
} e[3005];
int head[1005], ecnt;

void addedge(int u, int v, double w) {
  e[++ecnt] = {v, head[u], w};
  head[u] = ecnt;
}

double x[1005], n, s;

bool spfa() {
  vector<double> d(n+1);
  vector<int> vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 0; i <= n; ++i) q.push(i);
  d[0] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      double w = e[i].w;
      if(d[v] < d[u]*w) {
        d[v] = d[u]*w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n+1) return 1;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 0;
}

bool check(double T) {
  ecnt = 0;
  for(int i = 0; i <= n; ++i) head[i] = 0;
  for(int i = 1; i <= s; ++i) {
    if(f[i].o == 1) {
      addedge(f[i].B, f[i].A, f[i].k-T);
    } else {
      addedge(f[i].B, f[i].A, 1/(f[i].k+T));
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(x[i]) {
      addedge(0, i, x[i]);
      addedge(i, 0, 1/x[i]);
    } 
  }
  return spfa();
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> n >> s >> t;
  for(int i = 1; i <= s; ++i) {
    cin >> f[i].o >> f[i].A >> f[i].B >> f[i].k;
  }
  for(int i = 1; i <= t; ++i) {
    int C; cin >> C;
    cin >> x[C];
  }
  if(!check(0)) cout << -1 << endl;
  else {
    double l = 0, r = 10;
    while(r-l > 1e-6) {
      double mid = (l+r)/2;
      if(check(mid)) l = mid;
      else r = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
  }
  return 0;
}