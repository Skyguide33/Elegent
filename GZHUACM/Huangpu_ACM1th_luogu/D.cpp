//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  double L, x, y; cin >> L >> x >> y;
  double pi = acos(-1);
  double angle = 2*pi/n;
  double R = L/(2*sin(pi/n));
  // cout << "R=" << R << endl;
  double ans = 0;
  for(int i = 0; i < n; ++i) {
    double px = R*cos(2*pi*i/n);
    double py = R*sin(2*pi*i/n);
    double d = hypot(px-x, py-y);
    // cout << px << ' ' << py << ' ' << d << endl;
    ans += angle*d;
  }
  cout << fixed << setprecision(6) << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}