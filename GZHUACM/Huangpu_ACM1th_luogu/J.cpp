//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  map<int, set<int>> mp;
  while(q--) {
    int t, a, b; cin >> t >> a >> b;
    if(t == 1) {
      mp[a].insert(b);
    } else if(t == 2) {
      if(mp[a].contains(b)) mp[a].erase(b);
    } else {
      if(mp[a].contains(b) && mp[b].contains(a)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}