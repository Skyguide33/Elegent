//2025/6/13
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
  int ans = 0;
  for(int i = 8; i <= 16; ++i) {
    for(int j = 0; j < s.size()-i+1; ++j) {
      string subs = s.substr(j, i);
      bool dig = 0, ch = 0;
      for(int k = 0; k < subs.size(); ++k) {
        if(isdigit(subs[k])) dig = 1;
        else if(!isalpha(subs[k])) ch = 1;
        if(dig && ch) break;
      }
      if(dig && ch) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}