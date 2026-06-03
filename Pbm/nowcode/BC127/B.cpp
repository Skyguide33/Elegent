//2026/1/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k, tt; cin >> n >> k;
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    ++a[tt%k];
  }
  bool flag = 1;
  for(int i = 0; i < k; ++i) {
    if(a[i]%2) {
      flag = 0;
      break;
    }
  }
  cout << (flag? "Yes": "No") << endl;
  return 0;
}