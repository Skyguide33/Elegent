//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int get_num(int num) {
  int res = 0;
  while(num) {
    res += num%10;
    num /= 10;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(get_num(i) == k) ++ans;
  }
  cout << ans << endl;
  return 0;
}