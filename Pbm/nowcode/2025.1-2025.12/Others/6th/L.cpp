//2025/7/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool b[200005];

struct interval {
  int l, r;
} a[100005];

bool cmp(interval& a, interval& b) {
  if(a.l == b.l) return a.r > b.r;
  return a.l > b.l;
}

void solve() {
  memset(b, 0, sizeof(b));
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> a[i].l >> a[i].r;
  sort(a+1, a+m+1, cmp);
  queue<int> p;
  int cntl = 0;
  for(int i = 1; i <= m; ++i) {
    if(!p.empty() && p.front() > a[i].r) p.pop();
    if(p.empty()) {
      b[a[i].l] = 1;
      p.push(a[i].l);
      if(cntl >= n) {
        cout << "-1\n";
        return;
      } else ++cntl;
    }
  }
  for(int i = 1; i <= 2*n; ++i) {
    if(b[i] == 0) {
      if(cntl < n) {
        cout << '(';
        ++cntl;
      } else cout << ')';
    } else cout << '(';
  }
  cout << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}