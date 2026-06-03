//2025/6/14
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int cnt = 0;
  for(int i = 1;; ++i) {
    if(__gcd(2024, i) == 1) ++cnt;
    if(cnt == 2024) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}