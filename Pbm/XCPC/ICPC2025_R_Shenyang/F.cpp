//2026/3/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int e[305][305], vis[305], stk[305], n, tail, rep, maxdep, dep, stop;

void dfs(int u) {
  dep = max(dep, tail);
  if(tail == maxdep) return;
  vis[u] = 1;
  stk[++tail] = u;
  for(int i = 1; i <= n; ++i) {
    if(!e[u][i] || i == stk[tail-1]) continue;
    if(vis[i]) {
      stk[++tail] = i;
      stop = 1;
    } else {
      dfs(i);
    }
    if(stop) break;
  }
  vis[u] = 0;
  if(!stop) --tail;
}

void solve() {
  int m, x, y; cin >> n >> m >> x >> y;
  memset(e, 0, sizeof(e));
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    e[u][v] = e[v][u] = 1;
  }
  if(e[x][y]) {
    maxdep = 3;
    while(1) {
      dep = stop = 0;
      tail = 0;
      memset(vis, 0, sizeof(vis));
      dfs(x);
      if(tail || dep < maxdep) break;
      ++maxdep;
    }
    if(!tail) {
      cout << "No" << endl;
      return;
    }
    cout << "Yes" << endl;
    set<int> st{stk[1]};
    set<pair<int, int>> st2;
    for(int i = 2; i <= tail; ++i) {
      cout << stk[i-1] << ' ' << stk[i] << endl;
      st.insert(stk[i]);
      st2.insert({stk[i-1], stk[i]});
    }
    if(!st.contains(y)) { 
      cout << y << ' ' << x << endl;
      st2.insert({y, x});
      st.insert(y);
    }
    for(int i = 1; i < n; ++i) {
      for(int j = i+1; j <= n; ++j) {
        if(e[i][j] && !st2.contains({i, j}) && !st2.contains({j, i})) {
          if(st.contains(i)) {
            cout << j << ' ' << i << endl;
          } else cout << i << ' ' << j << endl;
        }
      }
    }
  } else {
    cout << "Yes" << endl;
    for(int i = 1; i < n; ++i) {
      for(int j = i+1; j <= n; ++j) {
        if(e[i][j]) {
          if(i == x || i == y) {
            cout << j << ' ' << i << endl;
          } else cout << i << ' ' << j << endl;
        }
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}