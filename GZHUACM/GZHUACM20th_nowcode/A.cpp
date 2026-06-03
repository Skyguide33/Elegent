//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
void solve() {
  double x; cin >> x;
  double eps = x/1e6;
  double ans = 0;
  for(double t = -x; t < x; t += eps) {
    ans += (t*t*t*pow(2, cos(t))/(t*t+1)+t*sin(t*t)+4.0)*eps;
  }
  cout << setprecision(7) << fixed << ans << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}