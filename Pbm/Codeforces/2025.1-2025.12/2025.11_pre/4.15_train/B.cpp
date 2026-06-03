//2025/4/15
#include <bits/stdc++.h>
using namespace std;

string a[505];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) cout << a[i].find('#')+1 << ' ';
    cout << endl;
  }
  return 0;
}