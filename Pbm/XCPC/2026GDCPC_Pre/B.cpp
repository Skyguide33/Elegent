//2026/5/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[1000005], c[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= a[n]; ++i) {
    int pos = upper_bound(a+1, a+n+1, i)-a-1;
    b[i] = i/a[pos]+b[i%a[pos]];
    ++c[b[i]];
  }
  for(int i = 1; i <= a[n]; ++i) c[i] += c[i-1];
  while(q--) {
    int m; cin >> m;
    cout << c[min(m, a[n])] << ' ';
  }
  cout << endl;
  return 0;
}