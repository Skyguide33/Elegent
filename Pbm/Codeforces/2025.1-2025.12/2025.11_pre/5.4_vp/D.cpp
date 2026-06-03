//2025/5/4
#include <bits/stdc++.h>
using namespace std;

struct person { int a, b; } p[500005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
      cin >> p[i].a >> p[i].b;
    }
  }
  return 0;
}