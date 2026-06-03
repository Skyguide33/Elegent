//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[200005];

int find_set(int x) {
  return s[s[x]]==s[x]? s[x]: s[x] = find_set(s[x]);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) s[i] = i;
  while(m--) {
    int z, x, y; cin >> z >> x >> y;
    int sx = find_set(x), sy = find_set(y);
    if(z == 1) s[sx] = sy;
    else cout << (sx == sy? 'Y': 'N') << endl;
  }
  return 0;
}