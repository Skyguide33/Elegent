//2025/9/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD = 1000000007;

class Matrix {
public:
  int n;
  Matrix(int N, bool e = 0): n(N) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) arr[i][j] = 0;
    }
    if(e) for(int i = 1; i <= n; ++i) arr[i][i] = 1;
  } 
  friend istream& operator >> (istream &in, Matrix &M) {
    for(int i = 1; i <= M.n; ++i) {
      for(int j = 1; j <= M.n; ++j) in >> M.arr[i][j];
    }
    return in;
  }

  friend ostream& operator << (ostream &out, const Matrix &M) {
    for(int i = 1; i <= M.n; ++i) {
      for(int j = 1; j <= M.n; ++j) out << M.arr[i][j] << ' ';
      out << endl;
    }
    return out;
  }
  friend Matrix operator * (Matrix &x, Matrix &y) {
    Matrix res(x.n);
    for(int i = 1; i <= x.n; ++i) {
      for(int j = 1; j <= x.n; ++j) {
        for(int k = 1; k <= x.n; ++k) {
          res.arr[i][j] = (res.arr[i][j]+x.arr[i][k]*y.arr[k][j])%MOD;
        }
      }
    }
    return res;
  }
private: 
  ll arr[102][102];
};

Matrix fast_power(Matrix b, ll p) {
  Matrix res(b.n, 1);
  while(p) {
    if(p&1) res = res*b;
    b = b*b;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, k; cin >> n >> k;
  Matrix ans(n); cin >> ans;
  cout << fast_power(ans, k) << endl;
  return 0;
}