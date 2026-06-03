//2025/6/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, s, e, d;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> s >> e >> d;
  ll ans;
  if(e >= s) {
    ans = e - s;
    if(e >= s+d) ans = min(ans, e-(s+d));
    if(e >= s+n-d) {
      ans = min(ans, e-(s+n-d));
    } 
  } else {
    ans = e+n-s;
    if(e >= s-d) ans = min(ans, e-(s-d));
    if(e >= s-n+d) ans = min(ans, e-(s-n+d));
  }
  cout << ans << endl;
  return 0;
}