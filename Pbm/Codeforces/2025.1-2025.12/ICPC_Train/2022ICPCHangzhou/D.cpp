//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  double sum = 0;
  for(int i = 1; i<= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sum /= n+1;
  cout << setprecision(7) << fixed << sum*2 << ' ';
  for(int i = 2; i <= n; ++i) cout << setprecision(7) << fixed << sum << ' ';
  cout << endl;
  return 0;
}
