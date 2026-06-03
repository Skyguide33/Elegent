//2025/9/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int N = 1e6+5, M = 2e6+5;
int head[N], cnt;

struct edge {
  int from, to, next;
  int w;
} edge[M];

void init() {
  for(int i = 0; i < N; ++i) head[i] = -1;
  for(int i = 0; i < M; ++i) edge[i].next = -1;
  cnt = 0;
}

void addedge(int u, int v, int w) {
  edge[cnt].from = u;
  edge[cnt].to = v;
  edge[cnt].w = w;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  for(int i = 1; i <= n; ++i) cout << head[i] << ' ';
  cout << endl;
  for(int i = 0; i < m; ++i) cout << i << ' ';
  cout << endl;
  for(int i = 0; i < m; ++i) cout << edge[i].from << ' ';
  cout << endl;
  for(int i = 0; i < m; ++i) cout << edge[i].to << ' ';
  cout << endl;
  for(int i = 0; i < m; ++i) cout << edge[i].w << ' ';
  cout << endl;
  for(int i = 0; i < m; ++i)  cout << edge[i].next << ' ';
  cout << endl;
  return 0;
}