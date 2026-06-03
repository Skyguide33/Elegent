//2025/6/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;

struct edge{
  int u, v, w;
} e[1050000];

bool cmp(edge x, edge y) { return x.w < y.w; }

int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

void kruskal() {
  for(int i = 1; i <= m; ++i) {
    ll ans = 0;
    for(int i = 1; i <= n; ++i) s[i] = i;
    s[e[i].u] = s[e[i].v];
    ans += e[i].w;
    for(int i = 1; i <= m; ++i) {
      
    }
  }

}

int s[525000];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e+1, e+m+1, cmp);
  priority_queue<ll, vector<ll>, greater<ll>> q;
  kruskal();
  return 0;
}