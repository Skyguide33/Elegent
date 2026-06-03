//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2][200005];

void solve() {
  int n; cin >> n;
  map<int, vector<pair<int, int>>> pos;
  for(int i = 0; i < 2; ++i) {
    for(int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      pos[a[i][j]].push_back({i, j});
    }
  }
  array<set<int>, 2> st;
  st[0].insert(n+2);
  st[1].insert(-2);
  for(int i = 1; i <= n; ++i) st[0].insert(i), st[1].insert(i);
  auto add = [&](int num)->void {
    for(auto [i, j]: pos[num]) st[i].erase(j);
  };
  auto del = [&](int num)->void {
    for(auto [i, j]: pos[num]) st[i].insert(j);
  };
  auto check = [&]()->bool {
    if(st[0].contains(1) || st[1].contains(n)) return 0;
    if(*st[0].begin()-1 >= *st[1].rbegin()+1) return 1;
    return 0;
  };
  ll ans = 0;
  for(int l = 1, r = 0; l <= 2*n; ++l) {
    while(r < 2*n && !check()) add(++r);
    if(!check()) break;
    ans += 2*n-r+1;
    del(l);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}