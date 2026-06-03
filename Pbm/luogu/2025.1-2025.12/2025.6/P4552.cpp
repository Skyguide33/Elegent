//2025/6/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  vector<ll> a(100005);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = n; i >= 1; --i) a[i] -= a[i-1];
  ll p = 0, q = 0;
  for(int i = 2; i <= n; ++i) {
    if(a[i] >= 0) p += a[i];
    else q -= a[i];
  }
  cout << max(p, q) << endl << abs(p-q)+1 << endl;
  return 0;
}