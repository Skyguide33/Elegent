//2025/11/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  string s, t;
  for(int i = 1; i <= n; ++i) {
    cin >> t; 
    if(i%2 == 0) reverse(t.begin(), t.end());
    s += t;
  }
  int len = n*m;
  int ans = 0;
  for(int i = 0; i < len; ++i) {
    int pos = s.find("GZHU", i);
    if(pos != -1) {
      ++ans;
      i = pos+3;
    } else break;
  }
  cout << ans << endl;
  return 0;
}