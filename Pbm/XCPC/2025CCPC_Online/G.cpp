//2025/9/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q, t; cin >> n >> q;
  map<int, vector<int>> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> t;
    mp[t].push_back(i);
  }
  map<pair<int, int>, ll> ans;
  while(q--) {
    int x, y; cin >> x >> y;
    if(!ans.count({x, y})) {
      if(x == y) {
        int num = mp[x].size();
        ans[{x, y}] = 1ll*num*(num-1)/2;
      }
      ll res = 0;
      if(mp[x].size() < mp[y].size()) {
        for(auto &p: mp[x]) {
          res += mp[y].end()-lower_bound(mp[y].begin(), mp[y].end(), p);
        }
      } else {
        for(auto &p: mp[y]) {
          res += lower_bound(mp[x].begin(), mp[x].end(), p)-mp[x].begin();
        }
      }
      ans[{x, y}] = res;
    }
    cout << ans[{x, y}] << endl;
  }
  return 0;
}