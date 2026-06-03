//2025/6/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10000
#define N 61

ll mod = MOD, n, k;

class matrix {
public:
  matrix(int, int);
  void read();
  void print(int, int);
  int shape[2]; 
  ll m[N][N];
  friend matrix operator * (const matrix&, const matrix&);
};

matrix::matrix(int x, int y) {
  shape[0] = x, shape[1] = y;
  memset(m, 0, sizeof(m));
}

matrix operator * (const matrix& a, const matrix& b) {
  matrix c(a.shape[0], b.shape[1]);
  for(int i = 0; i < c.shape[0]; ++i) {
    for(int j = 0; j < c.shape[1]; ++j) {
      for(int k = 0; k < a.shape[1]; ++k) {
        c.m[i][j] = (c.m[i][j] + (a.m[i][k]*b.m[k][j])%mod) % mod;
      }
    }
  }
  return c;
}

matrix fast_power(matrix a, int n) {
  matrix res(a.shape[0], a.shape[1]);
  for(int i = 0; i < res.shape[0]; ++i) res.m[i][i] = 1;
  while(n) {
    if(n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

void matrix::read() {
  for(int i = 0; i < shape[0]; ++i) {
    for(int j = 0; j < shape[1]; ++j) cin >> m[i][j];
  }
}

void matrix::print(int x, int y) {
  for(int i = 0; i < x; ++i) {
    for(int j = 0; j < y; ++j) {
      cout << m[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k >> mod;
  matrix a(n, n), e(n, n);
  a.read();
  for(int i = 0; i < n; ++i) e.m[i][i] = 1;
  matrix s(2*n, 2*n);
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < n; ++k) {
        s.m[i*n+j][k] = a.m[j][k];
      }
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      s.m[n+i][n+j] = e.m[i][j];
    }
  }
  matrix f(a);
  // cout << "f.print():" << endl;
  // f.print(n, n);
  // cout << "s.print():" << endl;
  // s.print(2*n, 2*n);
  f.shape[1] = 2*n;
  for(int i = 0; i < n; ++i) f.m[i][i+n] = 1;
  s = fast_power(s, k-1);
  // cout << "s.print():" << endl;
  // s.print(2*n, 2*n);
  f = f * s;
  f.print(n, n);
  return 0;
}