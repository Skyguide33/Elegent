//2025/8/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

// y: 0 1 y = 1
// m: 1 2 3 ... 11 12 m = 12
// d: 1 2 3 ... 30 31 d = 31

int dp[100005], yr[100005][2], md[100005];

bool is_lunar(int year) {
  if((year%4 == 0 && year%100) || year%400 == 0) return 1;
  return 0;
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  map<int, int> m1, m2, m3, m4;
  for(int i = 0; i < n; ++i) {
    yr[i][0] = yr[i-1][0];
    yr[i][1] = yr[i-1][1];
    int t1 = s[i]-'0';
    for(auto& [x, y]: m3) {
      int t4 = x*10+t1;
      if(is_lunar(t4)) yr[i][1] += y;
      else yr[i][0] += y;
    }
    for(auto& [x, y]: m2) {
      int t3 = x*10+t1;
      if(m3.count(t3)) m3[t3] += y;
      else m2[t3] = y;
    }
    for(auto& [x, y]: m1) {
      int t2 = x*10+t1;
      if(m2.count(t2)) m2[t2] += y;
      else m2[t2] = y;
    }
    if(m1.count(t1)) ++m1[t1];
    else m1[t1] = 1;
  }
  cout << yr[n][0] << ' ' << yr[n][1] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}