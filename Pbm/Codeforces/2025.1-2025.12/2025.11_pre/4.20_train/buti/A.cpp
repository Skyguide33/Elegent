//2025/4/25
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    long long N, n, k, d; cin >> n >> d;
    int len = to_string(n).length();
    N = (1234567890+d) * pow(10, len);
    k = (N+n)/n;
    cout << k << endl;
  }
  return 0;
}