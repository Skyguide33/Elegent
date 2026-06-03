//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; 
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += (a[i] != b[i]);
  }
  cout << ans << endl;
  return 0;
}