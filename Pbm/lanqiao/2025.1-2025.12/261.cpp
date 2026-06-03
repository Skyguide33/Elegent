//2025/3/24
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
map<string, int> mp;

int bfs(string s1, string s2) {
  queue<string>q;
  q.push(s1);
  mp[s1] = 0;
  while(q.size()) {
    string ss = q.front(); q.pop();
    int dist = mp[ss];
    if(ss == s2) return dist;
    int k = ss.find('.');
    int x = k/3, y = k%3;
    for(int i = 0; i < 4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
      string tmp = ss;
      swap(tmp[k], tmp[nx*3+ny]);
      if(mp.count(tmp) == 0) {
        mp[tmp] = dist+1;
        q.push(tmp);
      }
    }
  }
  return -1;
}

int main() {
  string s1, s2; cin >> s1 >> s2;
  cout << bfs(s1, s2) << endl;
  
  return 0;
}