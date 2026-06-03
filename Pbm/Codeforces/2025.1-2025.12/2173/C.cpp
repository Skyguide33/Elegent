//2025/12/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n+1);
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; mp[a[i]] = 0;
  }
  bool flag = 1;
  vector<int> ans;
  for(auto &[x, y]: mp) {
    if(!y) {
      ans.push_back(x);
      y = 1;
      for(int i = x*2; i <= k; i += x) {
        if(!mp.count(i)) {
          flag = 0;
          break;
        } else mp[i] = 1;
      }
    }
    if(!flag) break;
  }
  if(flag) {
    int len = ans.size();
    cout << len << endl;
    for(int i = 0; i < len; ++i) cout << ans[i] << ' ';
    cout << endl;
  } else cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}