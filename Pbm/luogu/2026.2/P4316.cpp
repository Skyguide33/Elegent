//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w; };

vector<Edge> e[100005];
int in[100005];
long double p[100005], d[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    e[u].push_back({v, w});
    ++in[v];
  }
  d[1] = 0.;
  p[1] = 1.;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    int k = e[u].size();
    for(auto [v, w]: e[u]) {
      p[v] += p[u]/k;
      d[v] += (d[u]+p[u]*w)/k;
      if(!--in[v]) q.push(v);
    }
  }
  cout << setprecision(2) << fixed << d[n] << endl;
  return 0;
}