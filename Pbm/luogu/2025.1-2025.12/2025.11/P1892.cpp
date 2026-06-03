//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[2005];

int find_set(int x) {
  return (x == s[x]? x: s[x] = find_set(s[x])); 
}

void merge(int x, int y) {
  x = find_set(x), y = find_set(y);
  s[y] = x;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= 2*n; ++i) s[i] = i;
  while(m--) {
    char opt; int p, q; cin >> opt >> p >> q;
    if(opt == 'F') merge(p, q);
    else {
      merge(p, q+n);
      merge(q, p+n);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(i == s[i]) ++ans;
  }
  cout << ans << endl;
  return 0;
}