//2025/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, k; cin >> n >> k;
  ll del = 0;
  for(ll i = 1; i < n; ++i) {
    cin >> a[i]; a[i] += a[i-1];
    del = max(del, a[i] - a[(i-k>=0?i-k:0)]);
  }
  cout << a[n-1]-del << endl;
  return 0;
}