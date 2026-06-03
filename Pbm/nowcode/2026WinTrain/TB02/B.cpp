//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1);
  int maxi = 0, cnt = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] > a[maxi]) {
      maxi = i;
      cnt = 1;
    } else if(a[i] == a[maxi]) ++cnt;
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] == a[maxi]) {
      if(cnt%2 == 0) cout << 0;
      else cout << 1;
    } else {
      if(cnt%2 == 0) cout << 1;
      else cout << 0;
    } 
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}