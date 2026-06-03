//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  a[n+1] = 0;
  vector<pair<int, int>> q;
  int maxi = 0, maxn = 0, pre = -1;
  for(int i = 1; i <= n; ++i) {
    pre = -1;
    while(!q.empty() && q.back().second >= a[i]) {
      pre = q.back().first;
      q.pop_back();
    }
    if(pre != -1) {
      q.push_back({pre, a[i]});
      int d = i-pre;
      if(d > maxn) {
        maxn = d;
        maxi = i;
      }
    }
    else q.push_back({i, a[i]});
  }
  // cout << maxi << ' ' << maxn << endl;
  if(maxi) --a[maxi];
  int clp = a[n];
  ll ans = 0;
  for(int i = n-1; i >= 1; --i) {
    ans += max(0, a[i]-clp);
    clp = min(clp, a[i]);
  } 
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}