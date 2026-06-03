//2025/10/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

const double eps = 1e-8, pi = acos(-1.0);

// 判断浮点数和0的大小关系 -1< 0= 1>
int sgn(double x) {
  if(fabs(x) < eps) return 0;
  else return x < 0? -1: 1;
}

// 比较两个浮点数 -1x<y 0x==y 1x>y
int dcmp(double x, double y) {
  if(fabs(x-y) < eps) return 0;
  else return x < y? -1: 1;
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

// 点积
double Dot(Vector A, Vector B) { return A.x*B.x+A.y*B.y; }

// 向量的模长
double Len(Vector A) { return sqrt(Dot(A, A)); } 
double Len2(Vector A) { return Dot(A, A); } // 求模长的平方, 避免开方

// 向量A与向量B的夹角 (0<=angle<=pi/2)
double Angle(Vector A, Vector B) { return acos(Dot(A, B)/Len(A)/Len(B)); }

// 叉积
double Cross(Vector A, Vector B) { return A.x*B.y-A.y*B.x; }

// 由向量AB,AC构成的三角形或平行四边形的有向面积 (逆时针为正, 顺时针为负)
double Area(Point A, Point B, Point C) { return Cross(B-A, C-A)/2; } // 三角形的面积
double Area2(Point A, Point B, Point C) { return Cross(B-A, C-A); } // 平行四边形的面积

// 向量A逆时针旋转角度rad
Vector Rotate(Vector A, double rad) { 
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad)); 
}

// 向量A的单位法向量
Vector Normal(Vector A) { return Vector(-A.y/Len(A), A.x/Len(A)); }

// 检查两个向量是否平行或重合
bool Parallel(Vector A, Vector B) { return sgn(Cross(A, B)) == 0; }

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

// 线段类
typedef Line Segment;

// 点和直线的位置关系 -1左侧 0上 1右侧
int Point_line_relation(Point p, Line v) {
  return sgn(Cross(p-v.p1, v.p2-v.p1));
}

// 判断点是否在线段上 (包括端点)
bool Point_on_seg(Point p, Line v) {
  return sgn(Cross(p-v.p1, p-v.p2)) == 0 && sgn(Dot(p-v.p1, p-v.p2)) <= 0;
}

// 点到直线的距离
double Dis_point_line(Point p, Line v) {
  return fabs(Cross(p-v.p1, v.p2-v.p1))/Distance(v.p1, v.p2); 
}

// 点在直线上的投影
Point Point_line_proj(Point p, Line v) {
  double k = Dot(p-v.p1, v.p2-v.p1)/Len2(v.p2-v.p1);
  return v.p1+(v.p2-v.p1)*k;
}

// 点关于直线的对称点
Point Point_line_symmetry(Point p, Line v) {
  Point q = Point_line_proj(p, v);
  return q*2-p;
}

// 点到线段的距离
double Dis_point_seg(Point p, Segment v) {
  if(sgn(Dot(p-v.p1, v.p2-v.p1)) < 0 || sgn(Dot(p-v.p2, v.p1-v.p2)) < 0) 
    return min(Distance(p, v.p1), Distance(p, v.p2));
  return Dis_point_line(p, v);
}

// 两条直线的位置关系 -1相交 0平行 1重合
int Line_relation(Line v1, Line v2) {
  if(sgn(Cross(v1.p2-v1.p1, v2.p2-v2.p1)) == 0) {
    if(Point_line_relation(v1.p1, v2) == 0) return 1;
    else return 0;
  }
  return -1;
}

// 两条直线ab和cd的交点 需保证ab与cd不平行
Point Cross_Point(Point a, Point b, Point c, Point d) {
  double s1 = Cross(b-a, c-a), s2 = Cross(b-a, d-a); // 叉积有正负
  return Point(c.x*s2-d.x*s1, c.y*s2-d.y*s1)/(s2-s1);
}

// 两条线段是否相交 (不含端点)
bool Cross_segment(Point a, Point b, Point c, Point d) {
  double c1 = Cross(b-a, c-a), c2 = Cross(b-a, d-a);
  double d1 = Cross(d-c, a-c), d2 = Cross(d-c, b-c);
  return sgn(c1)*sgn(c2) < 0 && sgn(d1)*sgn(d2) < 0;
}

// 存储多边形各点(顺时针、逆时针均可)或用于求凸包或最近点对的点集
Point p[N];
int n;

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

// 点集的凸包 洛谷P2742
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
  return v; // 返回凸包的点的数量
}

// 平面最近点对 洛谷P1257
bool cmpxy(Point a, Point b) { 
  return sgn(a.x-b.x) < 0 || (sgn(a.x-b.x) == 0 && sgn(a.y-b.y) < 0);
}

Point tmp_p[N];

bool cmpy(Point a, Point b) { return sgn(a.y-b.y) < 0; }

double Closest_Pair(Point *p, int left, int right) {
  double dis = 1e20;
  if(left == right) return dis;
  else if(left+1 == right) return Distance(p[left], p[right]);
  int mid = (left+right)>>1;
  double d1 = Closest_Pair(p, left, mid);
  double d2 = Closest_Pair(p, mid+1, right);
  dis = min(d1, d2);
  int k = 0; 
  for(int i = left; i <= right; ++i) {
    if(fabs(p[mid].x-p[i].x) < dis) tmp_p[k++] = p[i];
  }
  sort(tmp_p, tmp_p+k, cmpy);
  for(int i = 0; i < k; ++i) {
    for(int j = i+1; j < k; ++j) {
      double t_dis = Distance(tmp_p[i], tmp_p[j]);
      if(sgn(t_dis-dis) >= 0) break;
      dis = min(dis, t_dis);
    }
  }
  return dis;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  p[0] = Point(-1, 0);
  p[1] = Point(1, 0);
  p[2] = Point(1, 1);
  p[3] = Point(-1, 1);
  cout << fixed << Line_relation(Line(Point(-1, -1), Point(1, 1)), Line(Point(2, 3), Point(4, 5))) << endl;
  return 0;
}