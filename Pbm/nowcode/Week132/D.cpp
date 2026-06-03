//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  int odd = 0;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
    if(a[i]&1) ++odd;
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += 1ll*(n-2)*a[i]+sum;
    if(a[i]&1) ans -= n-odd;
    else ans -= odd;
  }
  cout << (ans>>2) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}