//2025/11/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node { int to, next; } e[400005];
int head[200005], cnt;
int dep[200005], son[200005];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void solve() {
  int n, v; cin >> n;
  memset(e, 0, sizeof(e));
  memset(head, 0, sizeof(head));
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}