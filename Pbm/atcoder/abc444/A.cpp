//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int num = n%10;
  n /= 10;
  bool flag = 1;
  while(n) {
    if(n%10 != num) {
      flag = 0;
      break;
    }
    n /= 10;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}