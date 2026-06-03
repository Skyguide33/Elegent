//2025/9/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  int cnt0 = 0, cnts = 0, t;
  for(int i = 1; i <= n; ++i) {
    cin >> t;
    if(t == -1) ++cnts;
    else if(t == 0) ++cnt0;
  }
  cout << cnts%2*2+cnt0 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}