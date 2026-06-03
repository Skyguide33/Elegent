//2025/5/23
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b; cin >> a >> b;
  string ra[6], rb[6]; int rlen = 0;
  while(cin >> ra[rlen] >> rb[rlen]) ++rlen;
  set<string> s;
  queue<string> q;
  q.push(a);
  int ans = 0, count = 1;
  bool flag = 0;
  while(!q.empty() && ans <= 10) {
    string now = q.front(); 
    q.pop(); --count;
    if(now == b) { flag = 1; break; }
    if(s.find(now) == s.end()) {
      s.insert(now);
      for(int i = 0; i < rlen; ++i) {
        int head = 0, pos;
        pos = now.substr(head).find(ra[i]);
        while(pos != -1) {
          pos += head;
          string next = now;
          next.replace(pos, ra[i].length(), rb[i]);
          head = pos+1;
          if(s.find(next) == s.end()) q.push(next);
          pos = now.substr(head).find(ra[i]);
        }
      }
    }
    if(count == 0) { count = q.size(); ++ans; }
  }
  if(ans == 11 || flag == 0) cout << "NO ANSWER!" << endl;
  else cout << ans << endl;
  return 0;
}