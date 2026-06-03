//2025/11/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  if(n > m) swap(n, m);
  if(n == 3 && m == 3) cout << 8 << endl;
  else if(n > 2) cout << 1ll*n*m << endl;
  else if(n == 2) {
    cout << (m+1)/2 << endl;
  } else cout << 1 << endl;
  return 0;
}