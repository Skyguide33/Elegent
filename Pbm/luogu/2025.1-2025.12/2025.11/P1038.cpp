//2025/11/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 105

struct Edge { int to, w, next; } e[N];
int head[N], cnt;
ll a[N], u[N], in[N], layer[N], maxlay;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, p; cin >> n >> p;
  for(int i = 1; i <= n; ++i) cin >> a[i] >> u[i];
  while(p--) {
    int i, j, w; cin >> i >> j >> w;
    addedge(i, j, w);
    ++in[j];
  }
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 0) {
      q.push(i);
      a[i] += u[i];
      layer[i] = 1;
      maxlay = 1;
    }
  }
  while(!q.empty()) {
    int now = q.front(); q.pop();
    a[now] -= u[now];
    if(a[now] < 0) a[now] = 0;
    for(int i = head[now]; i; i = e[i].next) {
      int v = e[i].to, w = e[i].w;
      a[v] += a[now]*w;
      if(--in[v] == 0) {
        q.push(v);
        layer[v] = layer[now]+1;
        maxlay = max(maxlay, layer[v]);
      }
    }
  }
  bool flag = 0;
  for(int i = 1; i <= n; ++i) {
    if(layer[i] == maxlay && a[i] > 0) {
      cout << i << ' ' << a[i] << endl;
      flag = 1;
    }
  }
  if(!flag) cout << "NULL" << endl;
  return 0;
}