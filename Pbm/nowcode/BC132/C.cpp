//2026/5/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int, int> get_last(ll num) {
  int cnt = 0, pos1 = -1, pos2 = -1;
  while(num) {
    ++cnt;
    if(num&1) {
      pos2 = pos1;
      pos1 = cnt;
    }
    num >>= 1;
  }
  return { pos1, pos2 };
}

int sum(ll num) {
  if(num <= 0) return 0;
  auto [pos1, pos2] = get_last(num);
  int res = pos1-1;
  if(pos2 != -1) res += pos2;
  res += (pos1-1)*(pos1-2)/2;
  return res;
} 

void solve() {
  ll l, r; cin >> l >> r;
  cout << sum(r)-sum(l-1) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}