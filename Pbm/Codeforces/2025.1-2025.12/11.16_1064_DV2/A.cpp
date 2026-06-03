//2025/11/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt[26];

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  char ch = s[n-1];
  for(int i = n-2; i >= 0; --i) {
    if(s[i] != ch) ++cnt;
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}