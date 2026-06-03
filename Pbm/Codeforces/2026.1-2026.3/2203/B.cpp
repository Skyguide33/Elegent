//2026/2/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll x; cin >> x;
  vector<int> a;
  int sum = 0;
  while(x) {
    int tt = x%10;
    a.push_back(tt);
    sum += tt;
    x /= 10;
  }
  --a.back();
  sort(a.begin(), a.end());
  int ans = 0, len = a.size();
  for(int i = len-1; i >= 0; --i) {
    if(sum < 10) break;
    sum -= a[i]; ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}