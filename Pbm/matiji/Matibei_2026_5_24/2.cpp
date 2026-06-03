//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s[1005], t[1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> s[i];
  for(int i = 1; i <= m; ++i) cin >> t[i];
  for(int i = 1; i <= n; ++i) {
    int ans = 0;
    for(int j = 1; j <= m; ++j) {
      if(s[i].find(t[j]) == 0) ++ans;
    }
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}