//2025/8/
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;


int head[N], d[N], ans[N], n, cnt, num = 0, maxnum = 1e9;
// d[i]记录节点i为根的树的节点数
struct edge {
  int to, next;
} e[N<<1];

void init() {
  for(int i = 0; i < N; ++i) head[i] = -1; 
  int t = n*2;
  for(int i = 0; i < N<<1; ++i) e[i].next = -1;
  cnt = 0;
}

void addedge(int u, int v) {
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt++;
}

void dfs(int u, int fa) {
  d[u] = 1;
  int tmp = 0; // 记录最大子树数量
  for(int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if(v == fa) continue;
    dfs(v, u);
    d[u] += d[v];
    tmp = max(tmp, d[v]);
  }
  tmp = max(tmp, n-d[u]);
  if(tmp < maxnum) {
    maxnum = tmp;
    num = 0;
    ans[++num] = u;
  } else if(tmp == maxnum) ans[++num] = u;
}

int main() {
  scanf("%d", &n);
  init();
  for(int i = 1; i < n; ++i) {
    int u, v; scanf("%d %d", &u, &v);
    addedge(u, v); addedge(v, u);
  }
  dfs(1, 0);
  sort(ans+1, ans+num+1);
  for(int i = 1; i <= num; ++i) printf("%d ", ans[i]);
  return 0;
}