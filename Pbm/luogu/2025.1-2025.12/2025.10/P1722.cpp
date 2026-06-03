//2025/10/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 100

int c[201][201];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i <= 2*n; ++i) {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; ++j) c[i][j] = (c[i-1][j]+c[i-1][j-1])%MOD;
  }
  cout << (c[2*n][n]-c[2*n][n-1]+MOD)%MOD << endl;
  return 0;
}