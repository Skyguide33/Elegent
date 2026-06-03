//2026/5/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[8];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int r = 1000;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    r += tt;
    if(r >= 0) {
      if(r < 700) ++a[1];
      else if(r < 1100) ++a[2];
      else if(r < 1500) ++a[3];
      else if(r < 2000) ++a[4];
      else if(r < 2400) ++a[5];
      else if(r < 2800) ++a[6];
      else ++a[7];
    }
  }
  for(int i = 1; i <= 7; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}