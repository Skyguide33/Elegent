//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

void solve() {
  int n; cin >> n;
  int res; 
  for(int i = 1; i <= 2*n-2; i += 2) {
    cout << "? " << i << ' ' << i+1 << endl;
    cout.flush();
    cin >> res;
    if(res == 1) {
      cout << "! " << i << endl;
      cout.flush();
      return;
    }
  }
  cout << "? " << 2*n-3 << ' ' << 2*n-1 << endl;
  cout.flush();
  cin >> res;
  if(res == 1) cout << "! " << 2*n-3 << endl;
  else {
    cout << "? " << 2*n-2 << ' ' << 2*n-1 << endl;
    cout.flush();
    cin >> res;
    if(res == 1) cout << "! " << 2*n-2 << endl;
    else cout << "! " << 2*n << endl;
    cout.flush();
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}