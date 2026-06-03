//2025/4/7
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int f[45];
  f[1] = f[2] = 1;
  for(int i = 3;; i++) {
    f[i] = f[i-2] + f[i-1];
    if(f[i] > 20211001) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}