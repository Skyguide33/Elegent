//2025/7/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getmaxwide(ll x) {
  ll t = sqrt(x);
  for(ll i = t; i >= 2; --i) {
    if(x % i == 0) return i;
  }
  return 1;
}

void solve() {
  int n; cin >> n;
  ll sum = (1+n)*n/2;
  ll maxw = getmaxwide(sum);
  cout << 2*(maxw+(sum/maxw)) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}