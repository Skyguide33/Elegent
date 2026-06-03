//2025/10/26
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
// #define endl '\n'

struct edge {
  int to, next;
} e[105];
int head[105], cnt; 
int num[105], low[105], iscut[105], dfn;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
} 

void dfs(int u, int fa) {
  low[u] = num[u] = ++dfn;
  int child = 0;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(!num[v]) {
      ++child;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(low[v] >= num[u] && u != 1) iscut[u] = 1;
    } else if(num[v] < num[u] && v != fa) low[u] = min(low[u], num[v]);
  }
  if(u == 1 && child >= 2) iscut[1] = 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;
  while(1) {
    scanf("%d", &n);
    if(!n) break;
    memset(e, 0, sizeof(e));
    memset(head, 0, sizeof(head));
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(iscut, 0, sizeof(iscut));
    while(1) {
      int u; scanf("%d", &u);
      if(!u) break;
      while(getchar() != '\n') {
        int v; scanf("%d", &v);
        addedge(u, v);
      }
    }
    int ans = 0;
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) ans += iscut[i];
    printf("%d\n", ans);
  }
  return 0;
}