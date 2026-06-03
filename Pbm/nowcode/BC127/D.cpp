//2026/1/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[200005];
int r[200005], y[200005], w[200005], n, m, k;

bool check(int mid) {
  for(int i = 1; i <= n; ++i) r[i] = y[i] = w[i] = 0;
  for(int i = 1; i <= n; ++i) {
    r[i] = r[i-1];
    y[i] = y[i-1];
    w[i] = w[i-1];
    if(i > mid) {
      if(s[i-mid] == 'r') --r[i];
      else if(s[i-mid] == 'y') --y[i];
      else --w[i];
    }
    if(s[i] == 'r') ++r[i];
    else if(s[i] == 'y') ++y[i];
    else ++w[i];
  }
  for(int i = mid; i <= n; ++i) {
    if(r[i] < y[i]) swap(r[i], y[i]);
    if(r[i]*2+y[i]+min(w[i], m)*2 >= k) return 1;
  }
  return 0;
}

void solve() {
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) cin >> s[i];
  int l = 1, r = n+1;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  if(l == n+1) cout << -1 << endl;
  else cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}