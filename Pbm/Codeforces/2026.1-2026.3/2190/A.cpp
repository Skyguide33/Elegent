//2026/1/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<char> a(n+1);
  bool disorder = 0;
  a[0] = '0';
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] > a[i-1]) disorder = 1;
  }
  if(!disorder) {
    cout << "Bob" << endl;
    return;
  }
  cout << "Alice" << endl;
  bool prez = 1, metz = 0;
  vector<int> ans;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == '1') {
      if(prez) prez = 0;
      if(!metz) ans.push_back(i);
    } else {
      if(!prez) {
        metz = 1;
        ans.push_back(i);
      }
    }
  }
  cout << ans.size() << endl;
  for(auto x: ans) cout << x << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}