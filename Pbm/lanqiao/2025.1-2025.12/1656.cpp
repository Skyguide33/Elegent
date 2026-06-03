//2025/3/24
#include <bits/stdc++.h>
using namespace std;
const int N = 305;

int e[N][N], path[N][N], tax[N], n;

void input() {
  cin >> n;
  memset(e, 0x3f, sizeof(e));
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int x; cin >> x;
      if(x != -1) e[i][j] = x;
      path[i][j] = j;
    }
  }
}

void floyd() {
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        int t = e[i][k] + e[k][j] + tax[k];
        if(t < e[i][j]) {
          e[i][j] = t;
          path[i][j] = path[i][k];
        } else if(t == e[i][j] && path[i][k] < path[i][j]) 
          path[i][j] = path[i][k];
      }
    }
  }
}

void output() {
  int x, y;
  while(cin >> x >> y) {
    if(x == -1 && y == -1) break;
    cout << "From " << x << " to " << y << ": " << endl;
    cout << "Path: " << x;
    int k = x;
    while(k != y) {
      k = path[k][y];
      cout << "-->" << k;
    }
    cout << endl;
    cout << "Total cost: " << e[x][y] << endl;
  }
}

int main() {
  input(); floyd(); output();
  return 0;
}