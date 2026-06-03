//2025/2/19
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, nxt; } e[100005];
int head[50005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int ans[3], n, len, maxn = INT_MAX>>1;

int dfs(int u, int fa) {
  int sum = 1, num = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v == fa) continue;
    int tt = dfs(v, u);
    sum += tt;
    num = max(num, tt);
  }
  num = max(num, n-sum);
  if(num < maxn) {
    maxn = num;
    ans[len=1] = u;
  } else if(num == maxn && len < 2) {
    ans[++len] = u;
  }
  return sum;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  dfs(1, 0);
  sort(ans+1, ans+len+1);
  for(int i = 1; i <= len; ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}