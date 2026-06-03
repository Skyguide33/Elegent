//2026/4/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[200005];
ll cnt1[200005][26], sum[200005][26], cnt2[200005][26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  cin >> s;
  for(int i = 1; s[i-1]; ++i) {
    cnt1[i][s[i-1]-'a'] = 1;
    for(int j = 0; j < 26; ++j) {
      cnt1[i][j] += cnt1[i-1][j];
      sum[i][j] = sum[i-1][j]+cnt1[i][j];
    }
    for(int j = 0; j < 26; ++j) {
      cnt2[i][j] = cnt2[i-1][j]+cnt1[i-1][j]*cnt1[i][j];
    }
  }
  while(q--) {
    int l, r, x; cin >> l >> r >> x;
    if(r-l+1 < x) {
      cout << 0 << endl;
      continue;
    }
    ll ans = 0;
    if(x == 1) {
      for(int i = 0; i < 26; ++i) {
        ans += cnt1[r][i]-cnt1[l-1][i];
      }
    } else if(x == 2) {
      for(int i = 0; i < 26; ++i) {
        ll cnt = cnt1[r][i]-cnt1[l-1][i];
        ans += cnt*(cnt-1)/2;
      }
    } else {
      for(int i = 0; i < 26; ++i) {
        ans += cnt1[r][i]*(sum[r-1][i]-sum[max(0, l-2)][i])-(cnt2[r][i]-cnt2[l-1][i])-(r-l+1)*cnt1[l-1][i]*cnt1[r][i]+cnt1[l-1][i]*(sum[r][i]-sum[l-1][i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}