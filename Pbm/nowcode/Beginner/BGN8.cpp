//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int x, y; cin >> x >> y;
  if(x == y) cout << 0 << endl;
  else if(x == -y) cout << 3 << endl;
  else if(x == 0) cout << 2 << endl;
  else if(y == 0) cout << 1 << endl;
  else cout << -1 << endl;
  return 0;
}