//2026/2/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll samer[200005], nsamer[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  for(int i = n-2; i >= 0; --i) {
    samer[i] += samer[i+1];
    nsamer[i] += nsamer[i+1];
    if(s[i] == s[i+1]) ++samer[i];
    else ++nsamer[i];
  }
  ll ans = 0;
  for(int i = 1; i < n; ++i) {
    if(s[i] == s[i-1]) ans += nsamer[i];
    else ans += samer[i];
  }
  cout << ans+1 << endl;
  return 0;
}