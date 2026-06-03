//2025/4/
#include <bits/stdc++.h>
using namespace std;
#define MOD 7
#define N 200005

long long a[2*N], b[N], c[N];

long long quick(long long a, long long b) {
  while(a % b) a += MOD;
  return a / b;
}


void test() {
  long long a, b; cin >> a >> b;
  cout << quick(a, b) << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  // test();
  long long n; cin >> n;
  long long idx = 0;
  for(long long i = 1; i <= 2*n; ++i) {
    cin >> a[i]; 
    if(a[i] >= 0) {
      b[++idx] = a[i];
    }
  }
  sort(b+1, b+n+1);
  long long cnt = 0, len = 0, m = 1, z = 1, ans = 1;
  for(long long i = 1; i <= 2*n; ++i) {
    if(a[i] >= 0) {
      ++len; ++c[a[i]];
    } else {
      ++cnt;
      if(c[b[cnt]]) {
        //cout << "now=" << b[cnt] << ", a=" << c[b[cnt]] << ", b=" << len << endl;
        m =
        --c[b[cnt]]; --len;
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}