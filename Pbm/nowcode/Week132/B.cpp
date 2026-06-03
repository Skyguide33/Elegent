//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  while(n) {
    if(n) {
      int tt = n%10;
      if(tt == 0 || tt == 5) {
        cout << "YES" << endl;
        return;
      }
    }
    n /= 10;
  }
  cout << "NO" << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}