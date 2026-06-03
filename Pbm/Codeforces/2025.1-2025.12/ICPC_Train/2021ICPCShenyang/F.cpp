//2025/11/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int d[1005][26], lc[26];
string s; 

string get_str(int len) {
  string res;
  int num, ch;
  for(int i = 0; i < len; ++i) {
    num = 0; ch= s[i]-'a';
    for(int j = 0; j < 26; ++j) {
      num += (d[lc[ch]][j] != 0);
    }
    res.push_back('a'+num);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  cin >> s;
  int len = s.length();
  string ans = "a";
  for(int i = 1; i <= len; ++i) {
    memset(d, 0, sizeof(d));
    memset(lc, 0, sizeof(lc));
    for(int j = i-1; j >= 1; --j) {
      int ch = s[j]-'a';
      d[j-1][ch] = 1;
      lc[ch] = max(lc[ch], j);
      for(int k = 0; k < 26; ++k) d[j-1][k] += d[j][k]; 
    }
    // cout << "tt" << endl;
    string tmp = get_str(i);
    if(tmp > ans) ans = tmp;
  }
  cout << ans << endl;
  return 0;
}