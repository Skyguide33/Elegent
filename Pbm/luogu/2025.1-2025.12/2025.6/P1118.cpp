//2025/6/5
#include <bits/stdc++.h>
using namespace std;

int n, sum, ans[13], c[13], fact[13];
bool found = 0;

int C(int n, int m) {
  return fact[n]/fact[n-m]/fact[m];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> sum;
  fact[1] = fact[0] = 1;
  for(int i = 1; i <= n; ++i) {
    ans[i] = i;
    fact[i+1] = fact[i]*(i+1);
  }
  for(int i = 1; i <= n; ++i) {
    c[i] = C(n-1, i-1);
  }
  bool ctn = 1;
  while(ctn) {
    int res = 0;
    for(int i = 1; i <= n; ++i) {
      res += ans[i]*c[i];
      if(res > sum) break;
    }
    if(res == sum) {
      for(int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
      }
      cout << endl;
      return 0;
    }
    ctn = next_permutation(ans+1, ans+n+1);
  }
  return 0;
}