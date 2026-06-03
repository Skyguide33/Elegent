//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a+n);
  n = unique(a, a+n)-a;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      if((a[j]%a[i])%2 == 0) {
        cout << a[i] << ' ' << a[j] << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}