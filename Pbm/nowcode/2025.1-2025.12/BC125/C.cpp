//2025/12/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double a[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  double ans = a[1];
  for(int i = 2; i <= n; ++i) {
    ans = sqrt(ans*a[i]);
  }
  cout << setprecision(9) << fixed << ans << endl;
  return 0;
}