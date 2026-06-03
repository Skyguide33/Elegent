//2026/6/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

multiset<int> e[501];
stack<int> st;

int dg[501];

void eular(int u) {
  while(!e[u].empty()) {
    int v = *e[u].begin();
    e[u].erase(e[u].begin());
    auto it = e[v].find(u);
    e[v].erase(it);
    eular(v);
  }
  st.push(u);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    e[u].insert(v);
    e[v].insert(u);
    ++dg[u]; ++dg[v];
  }
  int src = 1;
  for(int i = 1; i <= 500; ++i) {
    if(dg[i]%2) {
      src = i;
      break;
    }
  }
  if(dg[src] == 0) {
    for(int i = 1; i <= 500; ++i) {
      if(dg[i]) {
        src = i;
        break;
      }
    }
  }
  eular(src);
  while(!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  } 
  return 0;
}