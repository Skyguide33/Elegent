//2025/4/20
#include <bits/stdc++.h>
using namespace std;

string S, P;
int ans, Next[1005];

void getNext(string &P, int plen) {
  Next[0] = Next[1] = 0;
  for(int i = 1; i < plen; ++i) {
    int j = Next[i];
    while(j && P[i] != P[j]) j = Next[j];
    if(P[i] == P[j]) ++j;
    Next[i+1] = j;
  }
}

void kmp(string &S, string &P) {
  int last = -1; 
  int slen = S.length(), plen = P.length();
  getNext(P, plen);
  int j = 0;
  for(int i = 0; i < slen; ++i) {
    while(j && S[i] != P[j]) j = Next[j];
    if(S[i] == P[j]) ++j;
    if(j == plen) {
      if(i - last >= plen) {
        ++ans;
        last = i;
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  while(cin >> S) {
    if(S == "#") break;
    cin >> P;
    ans = 0;
    kmp(S, P);
    cout << ans << endl;
  }
  return 0;
}