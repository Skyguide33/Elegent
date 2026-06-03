//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] > 2) {
      sum += a[i]-2;
      a[i] = 2;
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] == 1 && sum) ++a[i], --sum;
  }
  if(sum) cout << (sum%2? n-1: n) << endl;
  else {
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans += (a[i]%2 == 0);
    cout << ans << endl;
  }
  return 0;
}