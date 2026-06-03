//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int x; cin >> x;
  if(a[1] <= x && x <= a[n]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
 
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}