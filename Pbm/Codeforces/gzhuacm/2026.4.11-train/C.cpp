//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  string s; cin >> s;
  int h = stoi(s.substr(0, 2));
  cout << setw(2) << setfill('0') << (h+11)%12+1 << ':' << s.substr(3) << ' ';
  if(h >= 12) cout << "PM" << endl;
  else cout << "AM" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}