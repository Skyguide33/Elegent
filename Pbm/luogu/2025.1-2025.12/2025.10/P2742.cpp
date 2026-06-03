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
  bool operator < (Point B) { return sgn(x-B.x) < 0 || (sgn(x-B.x) == 0 && sgn(y-B.y) < 0); }
  friend ostream& operator << (ostream& out, Point A) {
    out << '(' << A.x << ", " << A.y << ')';
    return out;
  }
};

// 两点之间的距离
double Distance(Point a, Point b) { return hypot(a.x-b.x, a.y-b.y); }

// 向量类
typedef Point Vector;

// 叉积
double Cross(Vector A, Vector B) { return A.x*B.y-A.y*B.x; }

int Convex_hull(Point *p, int n, Point *ch) {
  n = unique(p, p+n)-p;
  sort(p, p+n);
  int v = 0;
  for(int i = 0; i < n; ++i) {
    while(v > 1 && sgn(Cross(ch[v-1]-ch[v-2], p[i]-ch[v-1])) <= 0) --v;
    ch[v++] = p[i];
  }
  int j = v;
  for(int i = n-2; i >= 0; --i) {
    while(v > j && sgn(Cross(ch[v-1]-ch[v-2], p[i]-ch[v-1])) <= 0) --v;
    ch[v++] = p[i];
  }
  if(n > 1) --v;
  return v;
}

Point p[100005], ch[100005];
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  n = Convex_hull(p, n, ch);
  double ans = 0;
  for(int i = 0; i < n; ++i) ans += Distance(ch[i], ch[(i+1)%n]);
  cout << setprecision(2) << fixed << ans << endl;
  return 0;
}