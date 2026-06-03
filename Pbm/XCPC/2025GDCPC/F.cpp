//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, a, b; cin >> n >> a >> b;
  int s; cin >> s;
  set<char> ac;
  map<char, int> mp;
  priority_queue<int, vector<int>, greater<int>> q;
  int ptl = 0, tac = 0;
  for(int i = 1; i <= s; ++i) {
    int t; char p; string v;
    cin >> t >> p >> v;
    if(ac.contains(p)) continue;
    if(v == "ac") {
      ptl += 20*mp[p]+t;
      ac.insert(p);
      ++tac;
    } else if(v == "rj") {
      ++mp[p];
    } else {  
      ac.insert(p);
      q.push(20*mp[p]+t);
    }
  }
  if(tac > a || (tac == a && ptl < b)) {
    cout << 0 << endl;
    return;
  }
  int ans = 0;
  while(!q.empty()) {
    ptl += q.top(); q.pop();
    ++ans;
    ++tac;
    if(tac > a || (tac == a && ptl < b)) {
      cout << ans << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}