//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  bool flag1 = 0, flag2 = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; 
    if(a[i]%2 == 0) flag1 = 1;
    else flag2 = 1;
  }
  if(flag1 && flag2) sort(a+1, a+n+1);
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}