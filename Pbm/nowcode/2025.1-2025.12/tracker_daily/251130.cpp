//2025/11/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int q; cin >> q;
  // map<int, int> mp;
  // int ans = 1;
  // mp[0] = 0; mp[300001] = 300001;
  // while(q--) {
  //   int l, r; cin >> l >> r;
  //   auto itl = mp.upper_bound(l), itr = itl; --itl;
  //   if(itl->second < l && itr->first > r) {
  //     ans = max(ans, r-l+2);
  //     mp[l] = r;
  //   }
  //   cout << ans << endl;
  // }
  int ans = 1;
  set<int> st;
  while(q--) {
    int l, r; cin >> l >> r;
    if(st.lower_bound(l) == st.upper_bound(r)) {
      ans = max(ans, r-l+2);
      st.insert(l); st.insert(r);
    }
    cout << ans << endl;
  }
  return 0;
}