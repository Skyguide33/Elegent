//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005], b[1000005];
map<int, int> mp[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) {
    ++mp[a[i]][b[i]];
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(mp[i].empty()) continue;
    vector<int> temp;
    for(auto [x, y]: mp[i]) {
      temp.push_back(y);
    }
    sort(temp.begin(), temp.end());
    for(int i = temp.size()-2; i >= 0; --i) ans += temp[i];
  }
  cout << ans << endl;
  return 0;
}