//2026/3/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

int nxt[N], ans[N], cnt;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s, p; cin >> s >> p;
  int plen = p.length(), slen = s.length();
  p = ' '+p;
  for(int i = 2, j = 0; i <= plen; ++i) {
    while(j && p[i] != p[j+1]) j = nxt[j];
    if(p[i] == p[j+1]) ++j;
    nxt[i] = j;
  }
  for(int i = 0, j = 0; i < slen; ++i) {
    while(j && s[i] != p[j+1]) j = nxt[j];
    if(s[i] == p[j+1]) ++j;
    if(j == plen) {
      ans[++cnt] = i+1-plen+1;
      j = nxt[j];
    }
  }
  for(int i = 1; i <= cnt; ++i) cout << ans[i] << endl;
  for(int i = 1; i <= plen; ++i) cout << nxt[i] << ' ';
  cout << endl;
  return 0;
}