//2026/5/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[n+1] = 0;
  bool flag = 1, asend = 0;
  int cnt = 0;
  for(int i = 1; i <= n+1; ++i) {
    if(a[i] < a[i-1]) {
      if(asend && cnt < 2) {
        flag = 0;
        break;
      } else {
        asend = 0;
        cnt = 1;
      }
    } else if(a[i] == a[i-1]) {
      ++cnt;
    } else {
      asend = 1;
      cnt = 1;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}