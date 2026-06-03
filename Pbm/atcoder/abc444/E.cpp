//2026/3/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[400005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, d; cin >> n >> d;
  set<int> num;
  num.insert({INT_MIN, INT_MAX});
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int l = 1;
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    auto it = num.lower_bound(a[i]), itl = it; --itl;
    while(abs(*itl-a[i]) < d || abs(*it-a[i]) < d) {
      num.erase(a[l++]);
      it = num.lower_bound(a[i]), itl = it; --itl;
    }
    num.insert(a[i]); 
    ans += i-l+1;
  }
  cout << ans << endl;
  return 0;
}