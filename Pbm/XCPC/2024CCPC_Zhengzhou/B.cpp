//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int, int> a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a+1, a+n+1);
  ll ans = 0;
  int used = 0;
  for(int i = 1; i <= n; ++i) {
    int num = max(0, (a[i].second-used))/a[i].first;
    used += num*a[i].first;
    ans += num;
  }
  cout << ans << endl;
  return 0;
}