//2025/8/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[1005];

int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) s[i] = i;
  while(m--) {
    int a, b; cin >> a >> b;
    int sa = find_set(a), sb = find_set(b);
    if(sa != sb) s[sa] = s[sb];
  }
  for(int i = 1; i <= n; ++i) find_set(i);
  int ans = 0;
  sort(s+1, s+n+1);
  for(int i = 1; i <= n; ++i) {
    if(s[i] != s[i-1]) ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}