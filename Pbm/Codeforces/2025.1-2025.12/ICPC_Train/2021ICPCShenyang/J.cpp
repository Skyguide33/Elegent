//2025/11/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[4], b[4];

map<string, int> mp;

void bfs() {
  queue<string> q;
  mp["0000"] = 0;
  q.push("0000"); 
  while(!q.empty()) {
    string now = q.front(); q.pop();
    for(int l = 0; l < 4; ++l) {
      for(int r = l; r < 4; ++r) {
        string add1 = now, sub1 = now;
        for(int i = l; i <= r; ++i) {
          add1[i] = (add1[i]-'0'+1)%10+'0';
          sub1[i] = (sub1[i]-'0'+9)%10+'0';
        }
        if(!mp.count(add1)) {
          mp[add1] = mp[now]+1;
          q.push(add1);
        }
        if(!mp.count(sub1)) {
          mp[sub1] = mp[now]+1;
          q.push(sub1);
        }
      }
    }
  }
}

void solve() {
  string a, b; cin >> a >> b;
  for(int i = 0; i < 4; ++i) b[i] = (b[i]-a[i]+10)%10+'0';
  cout << mp[b] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  bfs();
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}