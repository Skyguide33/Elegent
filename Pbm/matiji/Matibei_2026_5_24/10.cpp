//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int mean = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    mean += a[i];
  }
  mean /= n;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] >= mean) ++ans;
  }
  cout << ans << endl;
  return 0;
}