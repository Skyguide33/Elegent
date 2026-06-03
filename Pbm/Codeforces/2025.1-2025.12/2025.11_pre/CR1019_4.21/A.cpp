//2025/4/21
#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    sort(a+1, a+n+1);
    int pre = a[1], ans = n;
    for(int i = 2; i <= n; ++i) {
      if(a[i] == pre) --ans;
      else pre = a[i];
    }
    cout << ans << endl;
  }
  return 0;
}