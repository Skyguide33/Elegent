//2025/4/20
#include <bits/stdc++.h>
using namespace std;

int len, Next[1000005]; string s1; 

void getNext(string &s1, int len) {
  memset(Next, 0, sizeof(Next));
  for(int i = 1; i < len; ++i) {
    int j = Next[i];
    while(j && s1[i] != s1[j]) j = Next[j];
    if(s1[i] == s1[j]) ++j;
    Next[i+1] = j;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> len >> s1;
  getNext(s1, len);
  int mlen = len - Next[len];
  cout << mlen << endl;
  return 0;
}