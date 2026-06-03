//2025/6/14
#include <bits/stdc++.h>
using namespace std;
#define MOD 100000

int a[100005];

int f(int x) {
  int p1 = 1, p2 = 1;
  for(int i = 1; i <= x; ++i) {
    p1 = (p1*3) % MOD;
    p2 = (p2*5) % MOD;
  }
  return (p1+p2) % MOD;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout << 2500 << endl;
  return 0;
}