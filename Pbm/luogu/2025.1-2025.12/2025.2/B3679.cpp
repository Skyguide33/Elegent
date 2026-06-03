//2025/2/9
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  int x, y;
};

inline double Dis(Point &A, Point &B) {
  return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

inline bool Equal(Point &A, Point &B) {
  return (A.x == B.x && A.y == B.y);
}
int main() {
  int n, k, T, ans = 0;
  cin >> n >> k >> T;
  Point AllPos[n], SecPos[k], HunPos[T];
  for(int i = 0; i < n; i++) cin >> AllPos[i].x >> AllPos[i].y;
  for(int i = 0; i < k; i++) cin >> SecPos[i].x >> SecPos[i].y;
  for(int i = 0; i < T; i++) {
    cin >> HunPos[i].x >> HunPos[i].y;
    int MaxPos = 0;
    double MaxDis = 0, t;
    for(int j = 0; j < n; j++) {
      t = Dis(HunPos[i], AllPos[j]);
      if(MaxDis < t) {
        MaxPos = j;
        MaxDis = t;
      }
    }
    bool IsSec = 0;
    for(int j = 0; j < k; j++) {
      if(Equal(SecPos[j], AllPos[MaxPos])) {
        IsSec = 1;
        break;
      }
    }
    ans += IsSec;
  }
  cout << ans << endl;
  return 0;
}