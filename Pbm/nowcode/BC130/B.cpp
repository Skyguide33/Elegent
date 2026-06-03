//2026/3/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005], b[1000005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  if(n == 1) {
    if(a[1] == b[1]) {
      cout << "Yes" << endl;
    } else cout << "No" << endl;
    return;
  }
  for(int i = 1; i <= n-1; ++i) {
    int dist = a[i]-b[i];
    a[i] -= dist;
    a[i+1] -= dist;
  }
  if(a[n] == b[n]) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}