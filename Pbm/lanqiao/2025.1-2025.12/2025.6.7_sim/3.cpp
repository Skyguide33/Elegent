//2025/6/12
#include <bits/stdc++.h>
using namespace std;

int nums[4][4];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  for(unsigned i = 0; i < s.size(); ++i) {
    if(s[i] == 'b') ++nums[i%4][0];
    if(s[i] == 'l') ++nums[(i+3)%4][1];
    if(s[i] == 'u') ++nums[(i+2)%4][2];
    if(s[i] == 'e') ++nums[(i+1)%4][3];
  }
  int ans[4], num = 0;
  memset(ans, 0x3f, sizeof(ans));
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      ans[i] = min(ans[i], nums[i][j]);
    }
    num += ans[i];
  }
  if(num*4 == s.size() && ans[0] != num) --num;
  cout << num << endl;
}