#include <bits/stdc++.h>

typedef uint32_t ui;
int n, q, minK, maxK;
ui X, Y, Z;

ui nextInt(ui &x = X, ui &y = Y, ui &z = Z) {
  x ^= y << (z & 31);
  y ^= z >> (x & 31);
  z ^= x << (y & 31);
  x ^= x >> 5; y ^= y << 17; z ^= z >> 6;
  return x;
}

const int lim = 998'244'353;
std::vector<int> genArr(int n) {
  std::vector<int> ret(n);
  for (int i = 0; i < n; ++i) ret[i] = nextInt() % lim;
  return ret;
}

int main() {
  std::cin >> n >> q >> minK >> maxK;
  std::cin >> X >> Y >> Z;
  std::vector<int> a = genArr(n);
  for (int _ = 1; _ <= q; ++_) {
    int op = nextInt() % 3 + 1;
    if (op == 1) {
      int x = nextInt() % lim;
      
    } else if (op == 2) {
      int x = nextInt() % lim;
      //fill your code here
    } else {
      int k = nextInt() % (maxK - minK + 1) + minK;
      int p = nextInt() % (1 << k);
      //fill your code here
    }
  }
  //fill your code here
}