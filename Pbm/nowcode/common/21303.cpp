//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool dp[101][101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s, t; cin >> s >> t;
  dp[0][0] = 1;
  int slen = s.length(), tlen = t.length();
  for(int i = 1; i <= slen; ++i) {
    for(int j = 1; j <= tlen; ++j) {
      if(s[i-1] == t[j-1]) dp[i][j] |= dp[i-1][j-1];
      if(s[i-1] == ')') {
        int loc = i-1;
        int cnt = 1;
        while(cnt) {
          if(s[loc-1] == ')') ++cnt;
          else --cnt;
          --loc;
        }
        dp[i][j] |= dp[loc][j];
      }
    }
  }
  if(dp[slen][tlen]) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}