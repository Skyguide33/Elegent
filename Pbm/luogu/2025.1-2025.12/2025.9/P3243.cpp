//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int in[100005], topo[100005];
vector<int> e[100005];

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    e[i].clear(); in[i] = 0;
  }
  while(m--) {
    int u, v; cin >> u >> v;
    e[v].push_back(u); 
    ++in[u];
  }
  int tpcnt = 0;
  priority_queue<int> q;
  for(int i = 1; i <= n; ++i)
    if(!in[i]) q.push(i);
  while(!q.empty()) {
    int now = q.top(); q.pop(); 
    topo[++tpcnt] = now;
    for(int &x: e[now]) 
      if(!--in[x]) q.push(x);
  }
  if(tpcnt < n) cout << "Impossible!" << endl;
  else {
    for(int i = n; i >= 1; --i) cout << topo[i] << ' ';
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}