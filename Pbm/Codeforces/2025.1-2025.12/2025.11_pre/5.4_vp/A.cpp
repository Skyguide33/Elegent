//2025/5/4
#include <bits/stdc++.h>
using namespace std;

int s[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int y1; cin >> y1;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    int y2; cin >> y2;
    int ans = y2-y1+1;
    for(int i = 1; i <= n; ++i) {
      if(s[i] >= y1 && s[i] <= y2) --ans;
    }
    cout << ans << endl;
  }
  return 0;
}