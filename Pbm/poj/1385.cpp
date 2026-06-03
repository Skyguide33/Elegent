//2025/10/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const double eps = 1e-8;

// 判断浮点数和0的大小关系 -1< 0= 1>
int sgn(double x) {
  if(fabs(x) < eps) return 0;
  else return x < 0? -1: 1;
}

// 点类
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y): x(x), y(y) {}
  Point operator + (Point B) { return Point(x+B.x, y+B.y); }
  Point operator - (Point B) { return Point(x-B.x, y-B.y); }
  Point operator * (double k) { return Point(x*k, y*k); }
  Point operator / (double k) { return Point(x/k, y/k); }
  bool operator == (Point B) { return sgn(x-B.x) == 0 && sgn(y-B.y) == 0; }
  friend ostream& operator << (ostream& out, Point A) {
    out << '(' << A.x << ", " << A.y << ')';
    return out;
  }
} p[100005];

// 向量类
typedef Point Vector;

// 叉积
double Cross(Vector A, Vector B) { return A.x*B.y-A.y*B.x; }

// 多边形的有向面积 (逆时针为正, 顺时针为负)
double Polygon_area(Point *p, int n) {
  double area = 0;
  for(int i = 0; i < n; ++i) area += Cross(p[i], p[(i+1)%n]);
  return area/2;
}

// 多边形的重心
Point Polygon_center(Point *p, int n) {
  Point ans(0, 0);
  double area = Polygon_area(p, n);
  if(area == 0) return ans;
  for(int i = 0; i < n; ++i) 
    ans = ans+(p[i]+p[(i+1)%n])*Cross(p[i], p[(i+1)%n]);
  return ans/area/6;
}

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  Point ans = Polygon_center(p, n);
  cout << setprecision(2) << fixed << ans.x << ' ' << ans.y << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}
