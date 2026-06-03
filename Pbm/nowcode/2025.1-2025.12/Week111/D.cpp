//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005], m1[10][11], m2[10][11], e[10];

int getlen(ll num) {
  int res = 0;
  while(num) {
    num /= 10;
    ++res;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  e[0] = 1;
  int n; cin >> n;
  for(int i = 1; i <= 9; ++i) e[i] = e[i-1]*10;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    // cout << getlen(a[i]) << ' ';
    ++m1[getlen(a[i])][a[i]%11];
    for(int j = 1; j <= 9; ++j) {
      ++m2[j][a[i]*e[j]%11];
    }
  }
  // cout << endl;
  ll ans = 0;
  for(int i = 0; i <= 10; ++i) {
    // cout << i << ": " << endl;
    for(int j = 1; j <= 9; ++j) {
      ans += m1[j][i]*m2[j][(11-i)%11];
      // cout << format("m1[{0}][{1}]={2}, m2[{3}][{4}]={5}, mul={6}", j, i, m1[j][i], j, (11-i)%11, m2[j][(11-i)%11], m1[j][i]*m2[j][(11-i)%11]) << endl;
    }
  }
  // cout << m1[2][0] << ' ' << m2[2][0] << endl;
  for(int i = 1; i <= n; ++i) {
    if(a[i]%11 == 0) ans -= 1;
    else if((a[i]+(a[i]*e[getlen(a[i])]))%11 == 0) ans -= 1;
  }
  cout << ans << endl;
  return 0;
}