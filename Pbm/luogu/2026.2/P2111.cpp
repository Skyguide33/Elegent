//2026/2/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int c[51][51];

void init(){
  for(int i = 0; i <= 50; ++i) {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; ++j) {
      c[i][j] = c[i-1][j-1]+c[i-1][j];
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  int n, a, q; cin >> n >> a >> q;
  string s; cin >> s;
  int diff = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '0') ++diff;
  }
  if(q == 0) cout << "1.000" << endl;
  else {
    int err = n-q;
    double ans = 0.;
    for(int i = 0; i <= err; ++i) {
      for(int j = max(0, i-diff); j <= min(i,n-diff); ++j) {
        double res = 1.;
        for(int k = 1; k <= n-diff-j; ++k) res *= a/100.;
        for(int k = 1; k <= diff-(i-j); ++k) res *= (100-a)/100.;
        double ndf = 1., df = 1.;
        for(int k = 1; k <= j; ++k) ndf *= (100-a)/100.;
        for(int k = 1; k <= i-j; ++k) df *= a/100.;
        res *= c[n-diff][j]*ndf*c[diff][i-j]*df;
        ans += res;
      }
    }
    cout << setprecision(3) << fixed << ans << endl;
  }
  return 0;
}