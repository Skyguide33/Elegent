//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, minx; cin >> n >> minx;
  for(int i = 2; i <= n; ++i) {
    int tt; cin >> tt; 
    minx = min(minx, tt);
  }
  cout << minx << endl;
  return 0;
}