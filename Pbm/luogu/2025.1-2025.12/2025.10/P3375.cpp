//2025/10/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int Next[1000005], ans1[10000005], tail;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s, p; cin >> s >> p;
  // get next
  int plen = p.length(), j = 0;
  for(int i = 1; i < plen; ++i) {
    while(j && p[i] != p[j]) j = Next[j];
    if(p[i] == p[j]) ++j;
    Next[i+1] = j;
  }
  // kmp
  int slen = s.length(); j = 0;
  for(int i = 0; i < slen; ++i) {
    while(j && s[i] != p[j]) j = Next[j];
    if(s[i] == p[j]) ++j;
    if(j == plen) {
      ans1[tail++] = i+2-plen;
      j = Next[j];
    }
  }
  for(int i = 0; i < tail; ++i) cout << ans1[i] << endl;
  for(int i = 1; i <= plen; ++i) cout << Next[i] << ' ';
  cout << endl;
  return 0;
}