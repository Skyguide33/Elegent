//2026/5/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char a[2][200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  cin >> a[0] >> a[1];
  if(n%3) cout << -1 << endl;
  else {
    auto cale = [&](int l, const string &s0, const string &s1) {
      int res = 0;
      for(int i = 0; i < 3; ++i) {
        res += (a[0][l+i] != s0[i])+(a[1][l+i] != s1[i]);
      }
      return res;
    };
    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
    for(int i = 0; i < n; i += 3) {
      res1 += min(cale(i, "011", "001"), cale(i, "001", "011"));
      res2 += min(cale(i, "100", "110"), cale(i, "110", "100"));
      if(i/3%2) {
        res3 += cale(i, "000", "111");
        res4 += cale(i, "111", "000");
      } else {
        res3 += cale(i, "111", "000");
        res4 += cale(i, "000", "111");
      }
    }
    cout << min({res1, res2, res3, res4}) << endl;
  }
  return 0;
}