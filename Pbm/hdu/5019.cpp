//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll x, y, k; cin >> x >> y >> k;
  ll d = gcd(x, y);
  stack<ll> st1, st2;
  int t = sqrt(d);
  for(int i = 1; i <= t; ++i) {
    if(d%i == 0) {
      st1.push(i); st2.push(d/i);
    }
  }
  if(!st1.empty() && st1.top() == st2.top()) st2.pop();
  while(!st2.empty()) {
    st1.push(st2.top()); st2.pop();
  }
  while(!st1.empty()) {
    if(k == 1) {
      cout << st1.top() << endl;
      return;
    } else {
      st1.pop();
      --k;
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