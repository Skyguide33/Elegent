//2025/10/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 100000007

int c[6005][3005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i <= 2*n; ++i) {
    c[i][0] = 1;
    if(i <= n) c[i][i] = 1;
    int k = min(i, n);
    for(int j = 1; j <= k; ++j) c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
  }
  cout << (c[n*2][n]-c[n*2][n-1]+MOD)%MOD << endl;
  return 0;
}