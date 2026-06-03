//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int now = 0;
  string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
  string ans;
  for(char ch: s) {
    if(now == 0) {
      if(ch == '0' || ch == '5') now = 3;
      else if(ch == '2' || ch == '4') now = 1;
      else if(ch == '3') now = 2;
    } else if(now == 1) {
      if(ch == '0' || ch == '4') now = 2;
      else if(ch == '1') now = 3;
      else if(ch == '2' || ch == '5') now = 0;
    } else if(now == 2) {
      if(ch == '0' || ch == '5') now = 1;
      else if(ch =='2' || ch == '4') now = 3;
      else if(ch == '3') now = 0;
    } else {
      if(ch == '0' || ch == '4') now = 0;
      else if(ch == '1') now = 1;
      else if(ch == '2' || ch =='5') now = 2;
    }
    cout << now;
  }
  cout << endl;
  return 0;
}