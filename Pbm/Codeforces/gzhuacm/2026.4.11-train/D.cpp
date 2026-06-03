//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool is_bin_num(int num) {
  while(num) {
    if(num%10 > 1) return 0;
    num /= 10;
  }
  return 1;
}

bool dfs(int num) {
  if(is_bin_num(num)) return 1;
  for(int i = 2; i*i <= num; ++i) {
    if(num%i == 0 && is_bin_num(i)) {
      if(dfs(num/i)) return 1;
    }
  }
  return 0;
}

void solve() {
  int n; cin >> n;
  if(dfs(n)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}