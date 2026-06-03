//2025/11/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Op {
  int l, r;
} a[100005];

int b[100005];

bool cmp(const Op &x, const Op &y) {
  if(x.l == y.l) return x.r < y.r;
  return x.l < y.l;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> a[i].l >> a[i].r;
  sort(a+1, a+m+1, cmp);
  for(int i = 1; i <= m; ++i) {
    b[i] = max(b[i-1], a[i].r);
  }
  int ans = max(a[1].l-1, n-b[m]);
  for(int i = 2; i <= m; ++i) {
    if(a[i].l > b[i-1]) {
      ans = max(ans, a[i].l-b[i-1]-1);
    }
  }
  cout << ans << endl;
}