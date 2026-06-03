//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s[50005];
int cnt[50005][26];
char ans[50005];

int blk[50005][26];

void solve() {
  // cout << "testcase" << endl;
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 26; ++j) cnt[i][j] = 0;
  }
  for(int i = 1; i <= k; ++i) {
    cin >> s[i];
    for(int j = 0; j < n; ++j) ++cnt[j][s[i][j]-'a'];
  }
  for(int i = n; i >= 1; --i) {
    if(n%i) continue;
    int len = n/i;
    for(int j = 0; j < len; ++j) {
      for(int l = 0; l < 26; ++l) blk[j][l] = 1;
    }
    for(int j = 0; j < n; ++j) {
      for(int l = 0; l < 26; ++l) {
        if(!cnt[j][l]) blk[j%len][l] = 0;
      }
    }
    bool flag = 1;
    int idx = 0;
    for(int j = 0; j < len; ++j) {
      flag = 0;
      for(int l = 0; l < 26; ++l) {
        if(blk[j][l]) {
          flag = 1;
          ans[idx++] = 'a'+l;
          break;
        }
      }
      if(!flag) break;
    }
    if(flag) {
      // cout << len << endl;
      for(int j = 0; j < i; ++j) {
        for(int l = 0; l < len; ++l) cout << ans[l];
      }
      cout << endl;
      return;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}