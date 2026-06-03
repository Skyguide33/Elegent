//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}

void solve() {
  int n, m, tt; cin >> n >> m;
  map<int, int> a, b;
  for(int i = 1; i <= n; ++i) cin >> tt, ++a[tt];
  for(int i = 1; i <= m; ++i) cin >> tt, ++b[tt];
  while(!a.empty() && !b.empty()) {
    auto amax = a.end(), bmax = b.end(); --amax, --bmax;
    if(bmax->first > amax->first) ++b[bmax->first-amax->first];
    if(--bmax->second == 0) b.erase(bmax);
    if(b.empty()) break;
    amax = a.end(), bmax = b.end(); --amax, --bmax;
    if(amax->first > bmax->first) ++a[amax->first-bmax->first];
    if(--amax->second == 0) a.erase(amax);
  }
  if(a.empty()) cout << "Bob" << endl;
  else cout << "Alice" << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}