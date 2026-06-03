//2025/11/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int f(ll x) {
  if(x == 0) return 1;
  if(x%3 == 0) return f(x/3)+1;
  return f(x-1)+1;
}

int query2(ll l, ll r) {
  int maxnum = 0;
  for(ll i = l; i <= r; ++i) {
    maxnum = max(maxnum, f(i));
  }
  return maxnum;
}

int query1(ll l, ll r) {
  if(r-l <= 10) {
    int res = 0;
    for(ll i = l; i <= r; ++i) {
      res = max(res, f(i));
    }
    return res;
  } 
  int res = query1(l/3, (r-2)/3)+3;
  res = max({res, f(l), f(l+1), f(l+2), f(r), f(r-1), f(r-2)});
  return res;
}

void solve() {
  ll l, r; cin >> l >> r;
  cout << query1(l, r) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}