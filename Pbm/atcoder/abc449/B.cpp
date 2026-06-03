//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h, w, q; cin >> h >> w >> q;
  while(q--) {
    int t, p; cin >> t >> p;
    if(t == 1) {
      cout << p*w << endl;
      h -= p;
    } else {
      cout << p*h << endl;
      w -= p;
    }
  }
  return 0;
}