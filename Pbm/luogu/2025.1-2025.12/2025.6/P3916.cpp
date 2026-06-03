//2025/6/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int s[100005];

int find_set(int x) {
  if(x < s[x]) s[x] = find_set(s[x]);
  return s[x];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) s[i] = i-n;
  while(m--) {
    int u, v; cin >> u, v;
    int us = find_set(s[u]), vs = find_set(s[v]);
    s[us] = max(us, v); s[vs] = max(vs, u);
  }
  for(int i = 1; i <= n; ++i) {
    cout << find_set(i) << ' ';
  }
  cout << endl;
  return 0;
}