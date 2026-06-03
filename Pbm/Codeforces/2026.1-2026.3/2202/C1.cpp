//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[300005];

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int mina = -1, maxa = -1, ans = n;
  for(int i = 1; i <= n; ++i) {
    if(a[i] > maxa || a[i] < mina) {
      maxa = mina = a[i]+1;
    } else {
      maxa = a[i]+1;
      --ans;
    } 
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}