//2025/12/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[20];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  a[1] = 1;
  for(int i = 2; a[i-1] <= n; ++i) {
    a[i] = a[i-1]*i;
  }
  int x = 1, y = 1, minn = n;
  for(int i = 3; a[i-1] <= n; ++i) {
    int j = n/(a[i]-1);
    int t = abs(1ll*(a[i]-1)*j-n);
    if(t < minn && j != 2) {
      minn = t;
      x = i, y = j;
    }
    ++j;
    t = abs(1ll*(a[i]-1)*j-n);
    if(t < minn && j != 2) {
      minn = t;
      x = i, y = j;
    }
  }
  cout << x << ' ' << y << endl;
  return 0;
}