//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[31];

void solve() {
  ll n, c; cin >> n >> c;
  c <<= 30;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] <<= 30;
  }
  sort(a+1, a+n+1);
  int idx = n;
  while(idx) {
    while(idx && a[idx] > c) {
      --idx; 
    }
    if(idx == 0) break;
    --n;
    c >>= 1;
    --idx;
  }
  cout << n << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}