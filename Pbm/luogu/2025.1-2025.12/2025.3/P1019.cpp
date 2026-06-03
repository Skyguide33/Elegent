//2025/3/24
#include <bits/stdc++.h>
using namespace std;

string s[21];
int v[21], n, ans;

void dfs(string now) {
  ans = max(ans, int(now.length()));
  for(int i = 1; i <= n; i++) {
    if(v[i] >= 2) continue;
    for(int j = 1; j < min(now.length(), s[i].length()); j++) {
      if(now.substr(now.length()-j) == s[i].substr(0, j)) {
        v[i]++;
        dfs(now + s[i].substr(j));
        v[i]--;
      }
    } 
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> s[i];
  char ch; cin >> ch;
  for(int i = 1; i <= n; i++) {
    if(s[i][0] == ch) {
      v[i] = 1;
      dfs(s[i]);
      v[i] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}