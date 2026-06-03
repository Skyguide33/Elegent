//2025/9/4 树的重心
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 100005;

struct edge { int to; /* int w;*/ };

vector<edge> e[N];
int d[N], n;

struct node {
  int id, maxc;
} res[N];

void addedge(int u, int v) {
  e[u].push_back({v});
}

void dfs(int u, int fa) {
  d[u] = 1;
  int tmp = 0;
  int len = e[u].size();
  for(int i = 0; i < len; ++i) {
    int v = e[u][i].to;
    if(v == fa) continue;
    dfs(v, u);
    d[u] += d[v];
    tmp = max(tmp, d[v]);
  }
  tmp = max(tmp, n-d[u]);
  res[u].maxc = tmp;
}

bool cmp(node &x, node &y) { 
  if(x.maxc == y.maxc) return x.id < y.id;
  return x.maxc < y.maxc; 
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) res[i].id = i;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  dfs(1, -1);
  sort(res+1, res+n+1, cmp);  
  // int pre = res[1].maxc;
  for(int i = 1; i <= n; ++i) {
    // if(res[i].maxc != pre) break;
    cout << res[i].id << ' ';
  }
  cout << endl;
  for(int i = 1; i <= n; ++i) {
    // if(res[i].maxc != pre) break;
    cout << res[i].maxc << ' ';
  }
  cout << endl;
  return 0;
}