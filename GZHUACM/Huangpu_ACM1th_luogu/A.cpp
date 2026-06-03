//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[4];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int maxn = -1e9, minn = 1e9;
  for(int i = 0; i < 4; ++i) {
    cin >> a[i];
    maxn = max(maxn, a[i]);
    minn = min(minn, a[i]);
  }
  cout << maxn << ' ' << minn;
  return 0;
}