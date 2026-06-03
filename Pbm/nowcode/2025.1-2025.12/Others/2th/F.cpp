//2025/7/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long

char s[100005];
int n, t0;


void solve() {
  cin >> n >> t0;
  cin >> s;
  int maxzero = 0, cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] != '1') ++cnt;
    else {
      for(int j = i+1; j <= i+t0; ++j) {
        if(s[j%n] != '1') s[j%n] = '2';
        else break;
      }
      for(int j = i-1+n; j >= i-t0+n; --j) {
        if(s[j%n] != '1') s[j%n] = '2';
        else break;
      }
      maxzero = max(maxzero, cnt);
      cnt = 0;
    }
  }
  if(cnt) {
    for(int i = 0; i < n; ++i) {
      if(s[i] != '1') ++cnt;
      else {
        maxzero = max(maxzero, cnt);
        break;
      }
    }
  }
  if(maxzero <= t0+1) cout << 0 << endl;
  else {
    int burn = 0;
    for(int i = 0; i < n; ++i) {
      if(s[i] != '0') ++burn;
    }
    int ans = n - burn;
    ans -= max(0, maxzero - 2*t0);
    ans += maxzero - 1 - t0;
    cout << ans << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}