//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, x, tt; cin >> n >> x;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    if(!mp.contains(tt)) mp[tt] = 0;
    ++mp[tt];
  }
  int maxn = 0;
  for(auto [x, y]: mp) maxn = max(maxn, y);
  if(!mp.contains(x)) mp[x] = 0;
  cout << maxn-mp[x] << endl;
  return 0;
}