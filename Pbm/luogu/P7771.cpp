//2026/6/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> e[100005];
int idg[100005], odg[100005];
stack<int> st;

void eular(int u) {
  while(!e[u].empty()) {
    int v = e[u].back();
    e[u].pop_back();
    eular(v);
  }
  st.push(u);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    e[u].push_back(v);
    ++odg[u]; ++idg[v];
  }
  for(int i = 1; i <= n; ++i) sort(e[i].begin(), e[i].end(), greater<int>());
  int src = 0, des = 0;
  bool flag = 1;
  for(int i = 1; i <= n; ++i) {
    if(abs(idg[i]-odg[i]) > 1) flag = 0;
    if(idg[i] > odg[i]) {
      if(!des) des = i;
      else flag = 0;
    } else if(idg[i] < odg[i]) {
      if(!src) src = i;
      else flag = 0;
    }
    if(!flag) break;
  }
  if(!flag) cout << "No" << endl;
  else {
    if(!src) src = 1;
    eular(src);
    while(!st.empty()) {
      cout << st.top() << ' ';
      st.pop();
    }
    cout << endl;
  }
  return 0;
}