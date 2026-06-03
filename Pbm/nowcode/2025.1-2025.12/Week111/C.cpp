//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, k, x; cin >> n >> k >> x;
  k %= x;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = x-k+1; i <= x; ++i) cout << a[i] << ' ';
  for(int i = 1; i <= x-k; ++i) cout << a[i] << ' ';
  for(int i = x+1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}