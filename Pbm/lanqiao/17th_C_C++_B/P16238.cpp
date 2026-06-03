//2026/3/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], cnt0[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    a[i] = tt-a[i];
    cnt0[i] = cnt0[i-1];
    if(a[i] == 0) ++cnt0[i];
  } 
  int l = 1, maxres = 0, res = 0, maxcnt = 0;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == 0) continue;
    while(l < i && a[l] == 0) ++l;
    if(!mp.contains(a[i])) mp[a[i]] = 1;
    else ++mp[a[i]];
    maxcnt = max(maxcnt, mp[a[i]]);
    res = maxcnt-cnt0[i]+cnt0[l-1];
    if(res <= 1) {
      l = i;
      mp.clear();
      mp[a[i]] = 1;
      maxcnt = 1;
      res = 1;
    }
    maxres = max(maxres, res);
  } 
  cout << cnt0[n]+maxres << endl;
  return 0;
}