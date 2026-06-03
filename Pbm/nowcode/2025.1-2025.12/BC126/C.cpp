//2025/12/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, p, k; cin >> n >> p >> k;
  map<string, int> s;
  int an = 0, bn = 0, min_an = 1e9;
  for(int i = 1; i <= n; ++i) {
    string ss; int tt; cin >> ss >> tt;
    s[ss] = tt;
  }
  set<string> t;
  for(int i = 1; i <= k; ++i) {
    string ss; cin >> ss;
    t.insert(ss);
  }
  for(auto &[x, y]: s) {
    if(t.contains(x)) {
      min_an = min(min_an, y); 
      an += y;
    }
    else bn += y;
  }
  int minn = (an+bn+p-1)/p, maxn = min_an;
  if(minn > maxn) cout << -1 << endl;
  else cout << minn << ' ' << maxn << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}