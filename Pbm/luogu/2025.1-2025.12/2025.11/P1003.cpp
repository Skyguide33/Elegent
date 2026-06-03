//2025/11/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct { int id, x1, y1, x2, y2; } a[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int xd, yd;
  for(int i = 1; i <= n; ++i) {
    a[i].id = i;
    cin >> a[i].x1 >> a[i].y1 >> xd >> yd;
    a[i].x2 = a[i].x1+xd; 
    a[i].y2 = a[i].y1+yd; 
  }
  int x, y; cin >> x >> y;
  int ans = -1;
  for(int i = 1; i <= n; ++i) {
    if(a[i].x1 <= x && x <= a[i].x2 && a[i].y1 <= y && y <= a[i].y2) 
      ans = a[i].id;
  }
  cout << ans << endl;
  return 0;
}