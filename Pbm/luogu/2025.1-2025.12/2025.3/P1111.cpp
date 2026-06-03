//2025/3/29
#include <bits/stdc++.h>
using namespace std;

struct node{ int x, y, t; } e[100005];
int a[100005], n = 1;

bool cmp(node &p, node &q) { return p.t < q.t; }

inline int find_set(int& k) {
  if(k != a[k]) a[k] = find_set(a[k]);
  return a[k];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, ans; cin >> N >> M;
  for(int i = 1; i <= N; i++) a[i] = i;
  for(int i = 1; i <= M; i++)
    cin >> e[i].x >> e[i].y >> e[i].t;
  sort(e+1, e+1+M, cmp);
  for(int i = 1; i <= M; i++) {
    int x = find_set(e[i].x), y = find_set(e[i].y);
    if(x == y) continue;
    a[x] = y;
    ++n;
    ans = e[i].t;
  }
  if(n == N) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}