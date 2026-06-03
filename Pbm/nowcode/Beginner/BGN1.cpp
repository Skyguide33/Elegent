//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a[6];
  int ans = 0;
  for(int i = 1; i <= 5; ++i) {
    cin >> a[i];
    if(a[i] == 1) ans = i;
  }
  cout << ans << endl;
  return 0;
}