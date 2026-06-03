//2025/8/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct supply{
  int p, s;
} a[1005];

bool cmp(supply& a, supply& b) {
  return a.p+a.s < b.p+b.s;
}

void solve() {
  int n, b; cin >> n >> b;
  for(int i = 1; i <= n; ++i) cin >> a[i].p >> a[i].s;
  sort(a+1, a+n+1, cmp);
  int maxp = 0, sum = 0;
  int i = 1;
  while(1) {
    sum += a[i].p+a[i].s;
    maxp = max(maxp, a[i].p);
    if(sum > b || i == n) break;
    ++i;
  }
  if(sum > b && sum-(maxp+1)/2 > b) --i;
  cout << i << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}