//2025/10/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005], Next[1000005], st[1000005], top;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s, p; cin >> s >> p;
  // get_next
  int plen = p.length();
  for(int i = 1; i < plen; ++i) {
    int j = Next[i];
    while(j && p[i] != p[j]) j = Next[j];
    if(p[i] == p[j]) ++j;
    Next[i+1] = j;
  }
  // kmp
  int slen = s.length(), j = 0;
  for(int i = 0; i < slen; ++i) {
    a[i] = j; st[top++] = i;
    while(j && s[i] != p[j]) j = Next[j];
    if(s[i] == p[j]) ++j;
    if(j == plen) {
      top -= plen;
      j = a[st[top]];
    }
  }
  for(int i = 0; i < top; ++i) cout << s[st[i]];
  cout << endl;
  return 0;
}