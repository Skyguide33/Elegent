//2026/1/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005], f[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i]%b[i] == 0) {
      a[i] /= b[i]; 
      for(int j = 1; j <= 1000; ++j) {
        if(a[i]%j == 0) {
          ans += f[j][b[i]];
          ++f[b[i]][j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}