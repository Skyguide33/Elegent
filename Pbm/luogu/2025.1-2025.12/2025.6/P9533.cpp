//2025/6/2
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  unordered_map<int, int> cnt;
  ++cnt[0];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] ^= a[i-1];
    ++cnt[a[i]];
  }
  long long ans = 0;
  for(auto &[_, c]: cnt) ans += 1ll*c*(c-1)/2;
  cout << ans << endl;
  return 0;
}