//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  if(a[n] == -1 && a[1] != -1) a[n] = a[1];
  else if(a[n] != -1 && a[1] == -1) a[1] = a[n];
  else if(a[1] == -1 && a[n] == -1) a[1] = a[n] = 0;
  cout << abs(a[n]-a[1]) << endl;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == -1) cout << 0 << ' ';
    else cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}