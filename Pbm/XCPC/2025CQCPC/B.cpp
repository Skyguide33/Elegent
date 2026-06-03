//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int l[200005], r[200005], c[200005];

void solve() {
  int n, m; cin >> n >> m;
  set<int> st;
  map<int, vector<int>> srt, end;
  for(int i = 1; i <= m; ++i) {
    cin >> l[i] >> r[i] >> c[i];
    st.insert({l[i], r[i]});
    srt[l[i]].push_back(i);
    end[r[i]].push_back(i);
  }
  if(!st.contains(n) || !st.contains(1)) {
    cout << 0 << endl;
    return;
  }
  ll ans = 1e18, now = 0;
  for(int x: st) {
    if(x == n) break;
    for(int i: srt[x]) {
      now += c[i];
    }
    for(int i: end[x]) {
      now -= c[i];
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}