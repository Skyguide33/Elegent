//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int num[200005][26], sum[26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  string s;
  for(int i = 1; i <= n; ++i) {
    cin >> s;
    for(char ch: s) ++num[i][ch-'A'], ++sum[ch-'A'];
  }
  for(int i = 1; i <= n; ++i) {
    int sub = 0;
    for(int j = 0; j < 26; ++j) sum[j] -= num[i][j];
    for(int j = 0; j < 26; ++j) {
      if(num[i][j]) {
        if(!sum[j]) {
          sub = 1e9;
          break;
        }
        sub = max(sub, (num[i][j]+sum[j]-1)/sum[j]);
      }
    }
    for(int j = 0; j < 26; ++j) sum[j] += num[i][j];
    if(m >= sub) cout << m-sub << ' ';
    else cout << -1 << ' ';
  }
  cout << endl;
  return 0;
}