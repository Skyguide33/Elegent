//2026/2/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, A, B, C; cin >> n >> A >> B >> C >> a[1];
  for (int i = 2; i <= n; i++) a[i] = ((ll)a[i-1]*A+B)%100000001;
  for (int i = 1; i <= n; i++) a[i] = a[i] % C + 1;
  double ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += 1./(double)max(a[i], a[i%n+1]);
  }
  cout << setprecision(3) << fixed << ans << endl;
  return 0;
}