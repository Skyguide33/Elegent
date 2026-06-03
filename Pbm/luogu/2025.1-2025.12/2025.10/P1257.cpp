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

bool cmpxy(Point a, Point b) { 
  return sgn(a.x-b.x) < 0 || (sgn(a.x-b.x) == 0 && sgn(a.y-b.y) < 0);
}

bool cmpy(Point a, Point b) { return sgn(a.y-b.y) < 0; }

Point p[10005], tmp_p[10005];

double Closest_Pair(int left, int right) {
  double dis = 1e20;
  if(left == right) return dis;
  else if(left+1 == right) return Distance(p[left], p[right]);
  int mid = (left+right)>>1;
  double d1 = Closest_Pair(left, mid);
  double d2 = Closest_Pair(mid+1, right);
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
  int n; cin >> n;
  for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p+n, cmpxy);
  cout << setprecision(4) << fixed << Closest_Pair(0, n-1) << endl;
  return 0;
}