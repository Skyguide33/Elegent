//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int inv[3000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, p; cin >> n >> p;
  inv[1] = 1;
  for(int i = 2; i <= n; ++i) inv[i] = 1ll*(p-p/i)*inv[p%i]%p;
  for(int i = 1; i <= n; ++i) cout << inv[i] << endl;
  return 0;
}