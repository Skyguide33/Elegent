//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout.precision(2);
  double d[7], p[7], d1, c, d2; int n; cin >> d1 >> c >> d2 >> p[0] >> n;
  d[n+1] = d1/d2;
  for(int i = 1; i <= n; ++i) {
    cin >> d[i] >> p[i];
    d[i] /= d2;
  }
  if(c < d[n+1]-d[n]) {
    cout << "No Solution" << endl;
    return 0;
  } else if(n == 0) {
    cout << fixed << d[n+1]*p[0] << endl;
    return 0;
  }
  int last = 0; 
  double ans = d[1]*p[0], rest = 0;
  for(int i = 1; i <= n; ++i) {
    double dist = d[i+1]-d[i];
    if(p[i] <= p[last]) last = i;
    rest = min(dist, c-(d[i]-d[last]));
    ans += rest*p[last];
    if(rest < dist) {
      if(last == i) {
        cout << "No Solution" << endl;
        return 0;
      } else {
        last = i;
        ans += (dist-rest)*p[last];
      }
    }
  }
  cout << fixed << ans << endl;
  return 0;
}