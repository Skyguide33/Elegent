//2025/7/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846

struct Point{
  double x, y, d, angle;
} p[500005];

bool equal(double a, double b) {
  if(abs(a-b) <= 1e-8) return 1;
  else return 0;
}

double getangle(double x, double y) {
  double angle = 0;
  if(x == 0) {
    if(y > 0) angle = PI/2;
    else if(y < 0) angle = PI*3/2;
  } else if(x > 0) {
    angle = atan(y/x);
    if(angle < 0) angle += 2*PI;
  } else {
    if(y >= 0) angle = atan(y/x) + PI;
    else  angle = atan(y/x) + PI;
  }
  return angle;
}

bool cmp(Point a, Point b) {
  if(equal(a.d, b.d)) {
    return a.angle > b.angle;
  } else return a.d > b.d;
}

void solve() {
  int n; double x, y; cin >> n >> x >> y;
  for(int i = 1; i <= n; ++i) {
    cin >> p[i].x >> p[i].y;
    p[i].x -= x; p[i].y -= y;
    p[i].d = sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
    p[i].angle = getangle(p[i].x, p[i].y);
  }
  x = y = 0;
  sort(p+1, p+n+1, cmp);
  for(int i = 1; i <= n; ++i) {
    cout << p[i].angle << ' ';
  }
  cout << endl;
  cout.precision(7);
  if(!equal(p[1].d, p[2].d)) cout << fixed << 2*PI << endl;
  else {
    double ans = 0;
    int idx1 = 1, idx2 = 2;
    while(p[idx2].d == p[idx1].d) {
      ans = max(ans, min())
    }
    cout << fixed << ans << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}