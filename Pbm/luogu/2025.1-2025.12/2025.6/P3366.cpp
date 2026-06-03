//2025/6/12
#include <bits/stdc++.h>
using namespace std;

int n, m;
struct edge{
  int x, y, z;
} e[200005];

bool cmp(edge a, edge b) { return a.z < b.z; }

int s[5005];

int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

int kruskal() {
  for(int i = 1; i <= n; ++i) s[i] = i;
  int ans = 0, cnt = 0;
  for(int i = 1; i <= m; ++i) {
    if(cnt == n-1) break;
    int e1 = find_set(e[i].x);
    int e2 = find_set(e[i].y);
    if(e1 == e2) continue;
    s[e1] = e2;
    ans += e[i].z;
    ++cnt;
  }
  if(cnt == n-1) return ans;
  else return -1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> e[i].x >> e[i].y >> e[i].z;
  sort(e+1, e+m+1, cmp);
  int ans = kruskal();
  if(ans == -1) cout << "orz" << endl;
  else cout << ans << endl;
  return 0;
}