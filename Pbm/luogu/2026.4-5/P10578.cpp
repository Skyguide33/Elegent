//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<string, int> mp; 

vector<string> rotate(const string &s) {
  vector<string> res;
  char raw[3][3], ch[3][3];
  for(int i = 0; i < 9; ++i) {
    raw[i/3][i%3] = s[i];
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) ch[k][l] = raw[k][l];
      }
      swap(ch[i+1][j], ch[i+1][j+1]);
      swap(ch[i][j], ch[i+1][j]);
      swap(ch[i][j], ch[i][j+1]);
      string rs;
      for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) rs += ch[k][l];
      }
      res.push_back(rs);
    }
  }
  return res;
}

void solve() {
  string src;
  for(int i = 1; i <= 9; ++i) {
    char ch; cin >> ch;
    src += ch;
  }
  cout << mp[src] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s = "123456789";
  bool flag = 1;
  while(flag) {
    mp[s] = -1;
    flag = next_permutation(s.begin(), s.end());
  }
  queue<string> q;
  q.push(s);
  mp[s] = 0;
  while(!q.empty()) {
    string u = q.front(); q.pop();
    auto vs = rotate(u);
    for(string v: vs) {
      if(mp[v] == -1) {
        mp[v] = mp[u]+1;
        q.push(v);
      }
    }
  }
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}