//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int a[200010];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, tt; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    ++a[1]; --a[tt+1];
  }
  for(int i = 1; i <= 200006; ++i) {
    a[i] += a[i-1];
  }
  // for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  // cout << endl;
  int r = 0;
  for(int i = 1; i <= 200006; ++i) {
    r += a[i];
    a[i] = r%10;
    r /= 10;
    // cout << "r=" << r << endl;
  }
  bool flag = 0;
  for(int i = 200006; i >= 1; --i) {
    if(a[i]) flag = 1;
    if(flag) cout << a[i];
  }
  cout << endl;
  return 0;
}