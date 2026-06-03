//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int num = n%10;
  if(num == 0) cout << 1 << endl;
  else if(num%2 == 0) cout << 5 << endl;
  else if(n%10 == 5) cout << 2 << endl;
  else cout << 10 << endl;
  return 0;
}