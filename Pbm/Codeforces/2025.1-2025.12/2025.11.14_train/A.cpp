//2025/11/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int c[300005];

void solve() {
  int n, a; cin >> n >> a;
  for(int i = 1; i <= n; ++i) cin >> c[i];
  int sum1 = 0, sum2 = 0;
  for(int i = 1; i <= n; ++i) {
    if(abs(a-1-c[i]) < abs(a-c[i])) ++sum1;
    if(abs(a+1-c[i]) < abs(a-c[i])) ++sum2;
  }
  if(sum1 > sum2) cout << a-1 << endl;
  else cout << a+1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}