//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int sn[26], tn[26];

void solve() {
  string s, t; cin >> s >> t;
  for(int i = 0; i < 26; ++i) sn[i] = tn[i] = 0;
  int slen = s.length(), tlen = t.length();
  for(int i = 0; i < slen; ++i) ++sn[s[i]-'a'];
  for(int i = 0; i < tlen; ++i) ++tn[t[i]-'a'];
  for(int i = 0; i < 26; ++i) {
    if(tn[i] < sn[i]) {
      cout << "Impossible" << endl;
      return;
    }
  }
  int si = 0;
  while(tlen) {
    int ci = 0;
    for(; ci < 26; ++ci) {
      if(tn[ci] > sn[ci]) break;
    }
    if(si == slen || ci < s[si]-'a') {
      cout << char('a'+ci);
      --tn[ci]; --tlen;
    } else {
      cout << s[si];
      --sn[s[si]-'a']; --tn[s[si]-'a']; --tlen;
      ++si;
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}