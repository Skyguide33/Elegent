//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int ans = 0, maxn = 0;
  for(int i = 1; i <= 7; ++i) {
    int a, b; cin >> a >> b;
    if(a+b > 8 && a+b > maxn) {
      ans = i;
      maxn = a+b;
    }
  }
  cout << ans << endl;
  return 0;
}