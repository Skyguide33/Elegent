//2025/11/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101];

void solve() {
  int n; cin >> n;
  for(int i = 1 ; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for(int i = 2; i+1 <= n; i += 2) {
    if(a[i] != a[i+1]) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}