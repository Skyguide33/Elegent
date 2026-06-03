//2026/2/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[502][502];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  map<int, int> mp;
  for(int i = 1; i <= n*m; ++i) {
    int tt; cin >> tt;
    if(tt) ++mp[tt];
  }
  int ans1 = 0, ans2 = 0;
  while(!mp.empty()) {
    if(mp.begin()->second >= 2) {
      int cnt = mp.begin()->second/2, nxt_num = mp.begin()->first+1;
      mp[nxt_num] += cnt;
      ans1 += cnt;
      if(nxt_num >= k) ans2 += cnt;
    } 
    mp.erase(mp.begin());
  }
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}