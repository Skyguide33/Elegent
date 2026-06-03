//2025/11/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 80112002

struct Edge {int to, next; } e[500005];
int head[5005], cnt, in[5005], out[5005], num[5005];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    addedge(u, v);
    ++out[u];
    ++in[v];
  }
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 0) {
      num[i] = 1;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      num[v] = (num[v]+num[u])%MOD;
      if(--in[v] == 0) q.push(v);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(out[i] == 0) ans = (ans+num[i])%MOD;
  }
  cout << ans << endl;
  return 0;
}