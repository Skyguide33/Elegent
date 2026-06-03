//2026/1/3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
  int n, a, b, c; cin >> n >> a >> b >> c;
  string s; cin >> s;
  s += "##";
  // 52:0 20:1 50:2 5:3 2:4 0:5
  vector<int> cnt(6, 0);
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if(s.substr(i, 3) == "520") {
      ++ans;
      i += 2;
    } else if(s.substr(i, 2) == "52") {
      ++cnt[0];
      ++i;
    } else if(s.substr(i, 2) == "20") {
      ++cnt[1];
      ++i;
    } else if(s.substr(i, 2) == "50") {
      ++cnt[2];
      ++i;
    } else if(s[i] == '5') ++cnt[3];
    else if(s[i] == '2') ++cnt[4];
    else if(s[i] == '0') ++cnt[5];
  }
  int add1 = min(cnt[0], c);
  ans += add1; c -= add1;
  add1 = min(cnt[1], a); 
  ans += add1; a -= add1;
  add1 = min(cnt[2], b);
  ans += add1; b -= add1;

  add1 = min({cnt[3], b, c});
  int add2 = min({cnt[4], a, c});
  int add3 = min({cnt[5], a, b});
  if(add1 >= add2 && add1 >= add3) {
    ans += add1; b -= add1; c -= add1;
  } else if(add2 >= add1 && add2 >= add3) {
    ans += add2; a -= add2; c -= add2;
  } else {
    ans += add3; a -= add3; b -= add3;
  }
  ans += min({a, b, c});
  cout << ans << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}