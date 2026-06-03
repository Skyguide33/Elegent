//2026/2/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p[100005], v[100005], n, k, cnt;
double r, c;

pair<double, double> seg[100005];

bool check(double t) {
  // cout << "ck" << endl;
  cnt = 0;
  for(int i = 1; i <= n; ++i) {
    double rr = t*v[i];
    if(rr >= r) {
      double x = sqrt(rr*rr-r*r);
      seg[++cnt] = {p[i]-x, p[i]+x};
    }
  }
  sort(seg+1, seg+cnt+1);
  // cout << seg[1].first << ' ' << seg[1].second << endl;
  if(!cnt || seg[1].first > 0) return 0;
  double right = 0., n_right = 0.;
  int kc = 0, i = 0;
  while(i <= cnt) {
    bool flag = 1;
    while(i < cnt && seg[i+1].first <= right) {
      n_right = max(n_right, seg[++i].second);
      flag = 0;
    }
    if(flag) break;
    // cout << "new_r: " << n_right << endl;
    right = n_right;
    if(++kc == k) break;
  }
  // cout << "tt " << right << ' ' << c << endl;
  return right >= c;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k >> r >> c;
  // cout << "yy" << endl;
  for(int i = 1; i <= n; ++i) cin >> p[i] >> v[i];
  double l = 0., r = 10000000.;
  while(r-l > 1e-8) {
    // cout << "yy" << endl;
    double mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid; 
  }
  cout << setprecision(8) << fixed << l << endl;
  return 0;
}