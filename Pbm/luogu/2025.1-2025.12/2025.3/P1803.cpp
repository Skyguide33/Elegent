//2025/3/24
#include <bits/stdc++.h>
using namespace std;

struct line{
  int a, b;
} e[1000005];

inline bool cmp(line& x, line& y) { return x.b < y.b; };

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; 
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> e[i].a >> e[i].b;
  }
  sort(e+1, e+n+1, cmp);
  int ans = 0, last = 0;
  for(register int i = 1; i <= n; i++) {
    if(e[i].a >= last) {
      last = e[i].b; ans++;
    }
  }
  cout << ans << endl;
  return 0;
}