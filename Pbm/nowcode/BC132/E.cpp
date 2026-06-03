//2026/5/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p[500005], l[500005], r[500005], len;

void solve() {
  int n; cin >> n;
  fill(l+1, l+n+1, 0);
  fill(r+1, r+n+1, n+1);
  for(int i = 1; i <= n; ++i) cin >> p[i];
  stack<int> q;
  for(int i = 1; i <= n; ++i) {
    while(!q.empty() && p[q.top()] < p[i]) {
      r[q.top()] = i;
      q.pop();
    }
    q.push(i);
  }
  for(int i = n; i >= 1; --i) {
    while(!q.empty() && p[q.top()] < p[i]) {
      l[q.top()] = i;
      q.pop();
    }
    q.push(i);
  }
  for(int i = 1; i <= n; ++i) {
    ll res = 1ll*(i-l[i])*(n-i+1)+1ll*(r[i]-i)*i-1ll*(i-l[i])*(r[i]-i);
    cout << res << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}