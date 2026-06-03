//2025/10/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const double eps = 1e-8, pi = acos(-1.0);

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

// 向量类
typedef Point Vector;

// 点积
double Dot(Vector A, Vector B) { return A.x*B.x+A.y*B.y; }

// 直线类
struct Line {
  Point p1, p2;
  Line() {}
  // 两点确定一条直线
  Line(Point p1, Point p2): p1(p1), p2(p2) {}
  // 根据一个点和倾斜角angle确定一条直线, 其中0 <= angle < pi
  Line(Point p, double angle) {
    p1 = p;
    if(sgn(angle-pi/2) == 0) { p2 = (p1+Point(1, 0)); }
    else p2 = (p1+Point(1, tan(angle)));
  }
  // ax + by + c = 0确定一条直线
  Line(double a, double b, double c) {
    if(sgn(a) == 0) {
      p1 = Point(0, -c/b);
      p2 = Point(1, -c/b);
    } else if(sgn(b) == 0) {
      p1 = Point(-c/a, 0);
      p2 = Point(-c/a, 1);
    } else {
      p1 = Point(0, -c/b);
      p2 = Point(-c/a, 0); // p2 = Point(1, (-c-a)/b);
    }
  }
};

int Cross(const Point &a, const Point &b) {
  return a.x*b.y-a.y*b.x;
}

// 判断点是否在线段上
bool Point_on_seg(Point p, Line v) {
  return sgn(Cross(p-v.p1, p-v.p2)) == 0 && sgn(Dot(p-v.p1, p-v.p2)) <= 0;
}

// 点和多边形的位置关系 0外部 1内部 2边上 3顶点上
int Point_in_Polygon(Point pt, Point *p, int n) {
  for(int i = 0; i < n; ++i) if(pt == p[i]) return 3;
  for(int i = 0; i < n; ++i)
    if(Point_on_seg(pt, Line(p[i], p[(i+1)%n]))) return 2;
  int num = 0;
  for(int i = 0; i < n; ++i) {
    int j = (i+1)%n;
    int c = sgn(Cross(pt-p[j], p[i]-p[j]));
    int u = sgn(p[i].y-pt.y);
    int v = sgn(p[j].y-pt.y);
    if(c > 0 && u < 0 && v >= 0) ++num;
    else if(c < 0 && u >= 0 && v < 0) --num;
  }
  return num != 0;
}

void method1() {
  Point p[4];
  for(int i = 0; i < 4; ++i) {
    char t; cin >> t >> p[i].x >> t >> p[i].y >> t;
  }
  int l = 0, r = 0;
  for(int i = 0; i < 3; ++i) {
    int relation = Cross(p[3]-p[i], p[(i+1)%3]-p[i]);
    if(relation < 0) ++l;
    else if(relation > 0) ++r;
  }
  if(l == 3 || r == 3) cout << 1 << endl;
  else if(l && r) cout << 2 << endl;
  else if(l+r == 1) cout << 4 << endl;
  else cout << 3 << endl;
}

// 点和多边形的位置关系 0外部 1内部 2边上 3顶点上
void method2() {
  Point p[4];
  for(int i = 0; i < 4; ++i) {
    char t; cin >> t >> p[i].x >> t >> p[i].y >> t;
  }
  int res = Point_in_Polygon(p[3], p, 3);
  if(res == 0) cout << 2 << endl;
  else if(res == 1) cout << 1 << endl;
  else if(res == 2) cout << 3 << endl;
  else cout << 4 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  method2();
  return 0;
}