//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  if(n%2 || n == 2 || n == 4 || n == 10) cout << -1 << endl;
  else cout << (n+6)/8 << endl;
  return 0;
}