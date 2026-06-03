//2025/4/1
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    long long p[3], k; cin >> p[0] >> p[1] >> p[2] >> k;
    sort(p, p+3);
    long long a = p[0], b = p[1], c = p[2], ans = 0;
    for(int i = 1; i <= a; i++) {
      for(int j = 1; j <= b; j++) {
        long long s = i * j;
        if(k % s == 0) {
          long long r = k / s;
          if(r <= c) {
            ans = max(ans, (a-i+1)*(b-j+1)*(c-r+1));
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}