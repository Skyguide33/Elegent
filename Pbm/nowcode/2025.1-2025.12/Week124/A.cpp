//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a, b; cin >> a >> b;
  if(a == b) cout << "Draw" << endl;
  else cout << (a > b? "Alice": "Bob") << endl;
  return 0;
}