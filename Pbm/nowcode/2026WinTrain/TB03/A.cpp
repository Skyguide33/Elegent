//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int x; cin >> x;
  int tt = sqrt(x);
  if(tt*(tt+1) == x) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}