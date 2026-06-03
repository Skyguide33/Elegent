//2025/11/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[100005], b[100];

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(ll i = 2; i <= 100; ++i) {
    for(int j = 0; j < n; ++j) {
      if(gcd(i, a[j]) == 1) {
        cout << i << endl;
        return;
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}