//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n+1);
  vector<int> nxt(n+1);
  int w_num = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    w_num += (a[i] > 0);
    nxt[i] = max(nxt[i-1], a[i]+i);
  }
  if(w_num <= k) {
    cout << 0 << endl;
    return;
  }
  auto check = [&](int mid)->bool {
    int i = 1;
    while(i <= n && a[i] == 0) ++i;
    int cnt = 1, tim = 0;
    while(i <= n) {
      ++tim;
      i = nxt[i];
      if(i >= n) break;
      if(i == nxt[i]) {
        while(i <= n && a[i] == 0) ++i;
        if(i <= n) tim = 0, ++cnt;
      } else {
        if(tim == mid) {
          ++i;
          while(i <= n && a[i] == 0) ++i;
          if(i <= n) tim = 0, ++cnt;
        }
      }
    }
    return cnt <= k;
  };

  int l = 1, r = n;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  if(!check(l)) cout << -1 << endl;
  else cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}