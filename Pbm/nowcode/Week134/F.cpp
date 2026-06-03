//2025/8/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353
const int N = 2005;

int p[N<<1], n, slen;
char a[N], s[N<<1];
int dp1[N], dp2[N];

void change() {
  int k = 0; s[k++] = '$'; s[k++] = '#';
  for(int i = 0; i < n; ++i) {
    s[k++] = a[i]; s[k++] = '#';
  }
  s[k++] = '&';
  slen = k;
}

void manacher() {
  int R = 0, C;
  for(int i = 1; i < slen-1; ++i) {
    if(i < R) p[i] = min(p[(C<<1)-i], C+p[C]-i);
    else p[i] = 1;
    while(s[i+p[i]] == s[i-p[i]]) ++p[i];
    if(p[i]+i > R) {
      R = p[i]+i;
      C = i;
    } 
  }
}

void solve() {
  cin >> n;
  cin >> a; change();
  manacher();
  // for(int i = 0; i < slen; ++i) cout << s[i];
  // cout << endl;
  // for(int i = 0; i < slen; ++i) cout << p[i];
  // cout << endl;
  fill(dp1+1, dp1+n+1, 0);
  fill(dp2+1, dp2+n+1, 0);
  dp1[0] = 1;
  for(int i = 1; i <= n; ++i) {
    int R = i*2+1;
    // cout << "i=" << i << ", R=" << R << endl;
    for(int j = i*2; 2*j >= R; --j) {
      if(j+p[j] > R) {
        int len = R-j;
        // cout << "j=" << j << ", len=" << len << endl;
        // for(int k = i-len; k <= i; ++k) cout << a[k-1];
        // cout << endl;
        dp1[i] = (dp1[i-len]+dp1[i])%MOD;
        dp2[i] = (dp2[i]+dp2[i-len]+1ll*len*len*dp1[i-len])%MOD;
      }
    }
  }
  // for(int i = 1; i <= n; ++i) cout << dp2[i] << ' ';
  // cout << endl;
  cout << dp2[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}