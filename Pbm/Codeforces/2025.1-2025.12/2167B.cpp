//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[26], b[26];

void solve() {
  int n; cin >> n;
  for(int i = 0; i < 26; ++i) a[i] = b[i] = 0;
  char ch;
  for(int i = 1; i <= n; ++i) {
    cin >> ch; ++a[ch-'a'];
  }
  for(int i = 1; i <= n; ++i) {
    cin >> ch; ++b[ch-'a'];
  }
  for(int i = 0; i < 26; ++i) {
    if(a[i] != b[i]) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}