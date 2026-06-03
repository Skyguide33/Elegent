//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[100005], num[100005], ans[100005];

struct edge {
  int p, q, r;
} e[100005];

struct req {
  int id, k, v;
} r[100005];

int find_set(int &x) {
  int root = x;
  while(root != s[root]) root = s[root];
  while(x != root) {
    int t = s[x];
    s[x] = root;
    x = t;
  }
  return root;
}

void merge_set(int &x, int &y) {
  int rx = find_set(x), ry = find_set(y);
  s[rx] = ry;
  num[ry] += num[rx];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for(int i = 1; i < n; ++i) cin >> e[i].p >> e[i].q >> e[i].r;
  for(int i = 1; i <= q; ++i) {
    r[i].id = i; cin >> r[i].k >> r[i].v;
  }
  sort(e+1, e+n, [](edge &x, edge &y) { return x.r > y.r; });
  sort(r+1, r+q+1, [](req &x, req &y) { return x.k > y.k; });
  for(int i = 1; i <= n; ++i) s[i] = i, num[i] = 1;
  int i = 1;
  for(int j = 1; j <= q; ++j) {
    while(i < n && e[i].r >= r[j].k) {
      merge_set(e[i].p, e[i].q);
      ++i;
    }
    ans[r[j].id] = num[find_set(r[j].v)]-1;
  }
  for(int i = 1; i <= q; ++i) cout << ans[i] << endl;
  printf("");
  return 0;
}