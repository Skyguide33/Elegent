//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int b[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= 1000; ++i) b[i*i] = 1;
  for(int i = 1; i <= n; ++i) {
    int a; cin >> a;
    bool flag = 0;
    for(int j = 1; j <= a/2; ++j) {
      if(b[j] && b[a-j]) {
        flag = 1;
        break;
      }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}