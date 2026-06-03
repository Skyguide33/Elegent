//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> a(n+1);
  for(int i = n-1; i >= 0; --i) {
    a[i] += a[i+1]+(s[i] == '(');
  }
  for(int i = 0; i < n; ++i) {
    if(s[i] == ')' && a[i] >= 2) {
      cout << n-2 << endl;
      return;
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