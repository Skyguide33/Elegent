//2025/4/
#include <bits/stdc++.h>
using namespace std;

long long a[100005], b[100005];

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  long long n, s; cin >> n >> s;
  for(long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for(int i = 1; i <= n; ++i) {
    b[i] = b[i-1] + a[i];
  }
  long long ans = n;
  for(long long i = 1; i <= n; ++i) {
    if(b[i] == s) {
      ans = i;
    } else if(b[i] > s) {
      ans = i-1;
    } 
  }
  if(b[n] < s) {
    ans -= 1;
  }
  cout << ans << endl;
  return 0;
}