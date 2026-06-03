//2025/11/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[3];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, c1, c2; cin >> n >> c1 >> c2;
  c1 = min(c1, c2); 
  if(c2 >= 2*c1) {
    cout << n*3*c1 << endl;
    return 0;
  }
  int ans = 0;
  while(n--) {
    for(int i = 0; i < 3; ++i) {
      cin >> s[i];
    }
    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
      ans += c1+c2;
    } else ans += 3*c1;
  }
  cout << ans << endl;
  return 0;
}