//2025/4/1
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) {
    char a[4], b[4];
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << ' ' << b << endl;
  }
  return 0;
}