//2025/4/4
#include <bits/stdc++.h>
using namespace std;

long long f[10005], c[10005][10005];


int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, b; cin >> n >> m >> b;
  for(int i = 1; i <= n; i++) cin >> f[i];
  for(int i = 1; i <= m; i++) {
    int a, b; cin >> a >> b;
    cin >> c[a][b];
  }
  return 0;
}