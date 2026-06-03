//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s, t; cin >> s;
  for(int i = 1; i <= n; ++i)t += '0'+i%2; 
  vector<int> m1(1, 0), m2(1, 0);
  for(int i = 0; i < n; ++i) {
    if(s[i] != t[i]) m1.push_back((s[i]-'0'? 1: -1));
    else m2.push_back((s[i]-'0'? 1: -1));
  }
  // m1 = "0000111111111", m2 = "11110000000";
  int len1 = m1.size(), len2 = m2.size();
  int maxtt = 0, mintt = 0;
  int ans1 = 0;
  for(int i = 1; i < len1; ++i) {
    maxtt += m1[i];
    mintt += m1[i];
    if(maxtt < 0) maxtt = 0;
    else ans1 = max(ans1, maxtt);
    if(mintt > 0) mintt = 0;
    else ans1 = max(ans1, -mintt);
  }
  maxtt = 0, mintt = 0;
  int ans2 = 0;
  for(int i = 1; i < len2; ++i) {
    maxtt += m2[i];
    mintt += m2[i];
    if(maxtt < 0) maxtt = 0;
    else ans2 = max(ans2, maxtt);
    if(mintt > 0) mintt = 0;
    else ans2 = max(ans2, -mintt);
  }
  cout << min(ans1, ans2) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}