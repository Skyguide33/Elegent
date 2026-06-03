//2025/6/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p, q, n, m;
ll arr[35][3][3], a[3];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> p >> q >> a[1] >> a[2] >> n >> m;
  for(int i = 1; i <= 32; ++i) {
    arr[i][1][1] = ((arr[i-1][1][1]*arr[i-1][1][1])%m + (arr[i-1][1][2]*arr[i-1][2][1])%m)%m;
    arr[i][1][2] = ((arr[i-1][1][1]*arr[i-1][1][2])%m + (arr[i-1][1][2]*arr[i-1][2][2])%m)%m;
    arr[i][2][1] = ((arr[i-1][2][1]*arr[i-1][1][1])%m + (arr[i-1][2][2]*arr[i-1][2][1])%m)%m;
    arr[i][2][2] = ((arr[i-1][2][1]*arr[i-1][1][2])%m + (arr[i-1][2][2]*arr[i-1][2][2])%m)%m;
  }
  
  if(n <= 2) {
    cout << a[n]%m << endl;
    return 0;
  }
  
  ll now = 0, pre1 = a[2], pre2 = a[1];
  for(ll i = 0; (1ll<<i) <= n-2; ++i) {
    if((1ll<<i) & (n-2)) {
      now = ((pre1*arr[i][1][1])%m+(pre2*arr[i][2][1])%m)%m;
      pre2 = ((pre1*arr[i][1][2])%m+(pre2*arr[i][2][2])%m)%m;
      pre1 = now; 
    }
  }
  cout << now%m << endl;
  return 0;
}