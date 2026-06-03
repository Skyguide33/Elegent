//2026/2/25
#include <bits/stdc++.h>
#include "gmp.h"
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  auto srt = chrono::steady_clock::now();
  mpz_t b, c;
  mpz_init(b);
  mpz_init(c);
  mpz_set_ui(b, 3);
  mpz_pow_ui(c, b, 10000000);
  auto stop = chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<double, std::micro>(stop-srt).count();
  string res = mpz_get_str(0, 10, c);
  cout << "res: " << res << endl;
  cout << "time: " << fixed << elapsed/1000000 << endl;
  return 0;
}