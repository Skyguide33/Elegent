//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, a, b; cin >> n >> a >> b;
  int s; cin >> s;
  map<char, int> mp;
  set<int> ac;
  int ptl = 0, accnt = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 1; i <= s; ++i) {
    int t; char p; string u;
    cin >> t >> p >> u;
    if(ac.find(p) != ac.end()) continue;
    if(t < 240) {
      if(u == "ac") {
        ptl += t+20*mp[p];
        ac.insert(p);
        ++accnt;
      } else ++mp[p];
    } else {
      q.push(mp[p]*20+t);
      ac.insert(p);
    }
  }
  int ans = 0;
  while(!q.empty() && (accnt < a || (accnt == a && ptl >= b))) {
    ptl += q.top(); q.pop();
    ++accnt;
    ++ans;
  }
  if(accnt > a || (accnt == a && ptl < b)) cout << ans << endl;
  else cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}