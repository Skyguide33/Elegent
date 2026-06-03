//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, x1, y1, x2, y2; cin >> n >> y1 >> x1 >> y2 >> x2;
  if(x1 == x2 && (x1 == 1 || x1 == n)) {
    if(x1 == 1) {
      while(x1 < n) {
        cout << 'R'; ++x1;
      }
      if(y1 == 1) {
        cout << 'D'; y1 = 2;
      } else {
        cout << 'U'; y1 = 1;
      }
      while(x1 > x2) {
        cout << 'L'; --x1;
      }
    } else {
      while(x1 > 1) {
        cout << 'L'; --x1;
      }
      if(y1 == 1) {
        cout << 'D'; y1 = 2;
      } else {
        cout << 'U'; y1 = 1;
      }
      while(x1 < x2) {
        cout << 'R'; ++x1;
      }
    }
  } else if(x1 == x2 || (abs(x1-x2)+abs(y1-y2))%2 == 0) cout << -1;
  else if(x1 < x2) {
    int x = x1, y = y1;
    // cout << "x=" << x << ", y=" << y << endl;
    while(x > 1) {
      cout << 'L';
      --x;
    }
    if(y == 1) {
      cout << 'D'; y = 2;
    } else {
      cout << 'U'; y = 1;
    }
    while(x <= x1) {
      cout << 'R'; ++x;
    }
    while(x < x2) {
      if(y == 1) {
        cout << 'D'; y = 2;
      } else {
        cout << 'U'; y = 1;
      }
      cout << 'R'; ++x;
    }
    while(x < n) {
      cout << 'R'; ++x;
    }
    if(y == 1) {
      cout << 'D'; y = 2;
    } else {
      cout << 'U'; y = 1;
    }
    while(x > x2) {
      cout << 'L'; --x;
    }
  } else {
    int x = x1, y = y1;
    while(x < n) {
      cout << 'R';
      ++x;
    }
    if(y == 1) {
      cout << 'D'; y = 2;
    } else {
      cout << 'U'; y = 1;
    }
    while(x >= x1) {
      cout << 'L'; --x;
    }
    while(x > x2) {
      if(y == 1) {
        cout << 'D'; y = 2;
      } else {
        cout << 'U'; y = 1;
      }
      cout << 'L'; --x;
    }
    while(x > 1) {
      cout << 'L'; --x;
    }
    if(y == 1) {
      cout << 'D'; y = 2;
    } else {
      cout << 'U'; y = 1;
    }
    while(x < x2) {
      cout << 'R'; ++x;
    }
  }
  cout << endl;
  return 0;
}