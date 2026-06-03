//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 676767677

int a[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  if(n == 1) {
    if(a[1] == 1) cout << 2 << endl;
    else cout << 0 << endl;
    return;
  }
  vector<int> c(n+1, 1e9);
  c[1] = 0; 
  for(int i = 2; i <= n; ++i) {
    if(abs(a[i]-a[i-1]) > 1) {
      cout << 0 << endl;
      return;
    }
    if(c[i-1] == 1) {
      if(a[i] == a[i-1]) c[i] = 0;
      else if(a[i-1] > a[i]) c[i] = 1;
      else break;
    } else {
      if(a[i] == a[i-1]) c[i] = 1;
      else if(a[i-1] < a[i]) c[i] = 0;
      else break;
    }
  }
  int cnt = 1, ans = 0;
  for(int i = 2; i <= n; ++i) {
    cnt += c[i];
    if(cnt > 1e9) break;
  }
  if(cnt == a[1]) ++ans;
  fill(c.begin(), c.end(), 1e9);
  c[1] = 1; 
  for(int i = 2; i <= n; ++i) {
    if(abs(a[i]-a[i-1]) > 1) {
      cout << 0 << endl;
      return;
    }
    if(c[i-1] == 1) {
      if(a[i] == a[i-1]) c[i] = 0;
      else if(a[i-1] > a[i]) c[i] = 1;
      else break;
    } else {
      if(a[i] == a[i-1]) c[i] = 1;
      else if(a[i-1] < a[i]) c[i] = 0;
      else break;
    }
  }
  cnt = 1;
  for(int i = 2; i <= n; ++i) {
    cnt += c[i];
    if(cnt > 1e9) break;
  }
  if(cnt == a[1]) ++ans;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}