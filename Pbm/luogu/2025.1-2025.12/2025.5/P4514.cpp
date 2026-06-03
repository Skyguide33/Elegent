//2025/5/6 rewrite 5/5
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

int n, m;
int t1[2050][2050], t2[2050][2050], t3[2050][2050], t4[2050][2050]; 

void update(int x, int y, int d) {
  for(int i = x; i <= n; i += lowbit(i)) {
    for(int j = y; j <= m; j += lowbit(j)) {
      t1[i][j] += d; t2[i][j] += d*y;
      t3[i][j] += d*x; t4[i][j] += d*x*y;
    }
  }
}

int sum(int x, int y) {
  int ans = 0;
  for(int i = x; i > 0; i -= lowbit(i)) {
    for(int j = y; j > 0; j -= lowbit(j)) {
      ans += (x+1)*(y+1)*t1[i][j] - (x+1)*t2[i][j] - (y+1)*t3[i][j] + t4[i][j];
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  char ch; cin >> ch >> n >> m;
  while(cin >> ch) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(ch == 'L') {
      int delta; cin >> delta;
      update(a, b, delta); update(a, d+1, -delta);
      update(c+1, b, -delta); update(c+1, d+1, delta);
    } else {
      cout << sum(c, d) - sum(a-1, d) - sum(c, b-1) + sum(a-1, b-1) << endl;
    }
  }
  return 0;
}