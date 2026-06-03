//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[500005];
int cnt[500005][26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, l, r; cin >> n >> l >> r;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    cnt[i][s[i]-'a'] = 1;
    for(int j = 0; j < 26; ++j) cnt[i][j] += cnt[i-1][j];
  }
  ll ans = 0;
  for(int i = 1; i+l <= n; ++i) {
    ans += cnt[min(i+r, n)][s[i]-'a']-cnt[i+l-1][s[i]-'a'];
  }
  cout << ans << endl;
  return 0;
}