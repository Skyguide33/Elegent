//2026/4/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) {
    string s; cin >> s;
    while(s.back() == ' ') s.pop_back();
    reverse(s.begin(), s.end());
    while(s.back() == ' ') s.pop_back();
    reverse(s.begin(), s.end());
    for(char &ch: s) {
      if(isalpha(ch) && ch != 'I') ch |= 32;
    }
    while(1) {
      int pos = s.find("can you");
      if(pos == -1) break;
      s = s.substr(0, pos)+"I can"+s.substr(pos+7);
    }
    while(1) {
      int pos = s.find("could you");
      if(pos == -1) break;
      s = s.substr(0, pos)+"I could"+s.substr(pos+9);
    }
    while(1) {
      
    }
    while(1) {
      int pos = s.find('?');
      if(!pos == -1) break;
      s[pos] = '!';
    }
  }
  return 0;
}