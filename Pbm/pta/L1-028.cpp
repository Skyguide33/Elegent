//2026/4/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) {
    int num; cin >> num;
    int snum = sqrt(num);
    bool flag = 1;
    for(int i = 2; i <= snum; ++i) {
      if(num%i == 0) {
        flag = 0;
        break;
      }
    }
    if(flag && num != 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}