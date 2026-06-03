//2025/3/28
#include <bits/stdc++.h>
using namespace std;

int a[5001]; 

int find_set(int x) {
  if(a[x] != x) a[x] = find_set(a[x]);
  return a[x];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, p; cin >> n >> m >> p;
  for(int i = 1; i <= n; i++) a[i] = i;
  while(m--) {
    int x, y; cin >> x >> y;
    x = find_set(x); y = find_set(y);
    if(a[x] != a[y]) a[x] = a[y];
  }
  while(p--) {
    int x, y; cin >> x >> y;
    if(find_set(x) == find_set(y)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}