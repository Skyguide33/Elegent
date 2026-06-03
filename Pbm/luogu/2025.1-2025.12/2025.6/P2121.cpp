//2025/6/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;

struct edge{
  int u, v;
  ll w;
} e[100005];

int s[100005];

bool cmp(edge x, edge y) { return x.w > y.w; }

int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e+1, e+m+1, cmp);
  for(int i = 1; i <= n; ++i) s[i] = i;
  int cnt = 0, end = min(n-1, k);
  ll ans = 0;
  for(int i = 1; i <= m; ++i) {
    if(cnt == end) break;
    int e1 = find_set(e[i].u);
    int e2 = find_set(e[i].v);
    if(e1 == e2) continue;
    s[e1] = e2;
    ans += e[i].w;
    ++cnt;
  }
  cout << ans << endl;
  return 0;
}