//2025/11/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005

int son[N][26], isend[N], vis[N], visx[10005], cnt, num, found;
string s;

void Insert(const string &s) {
  int p = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!son[p][ch]) son[p][ch] = ++cnt;
    p = son[p][ch];
  }
  isend[p] = 1;
}

void dfs(int p, size_t idx, bool op) {
  if(idx == s.length() && isend[p]) {
    if(op) {
      if(!vis[p]) vis[visx[++num] = p] = 1;
      return;
    } else found = 1;
  }
  int ch = s[idx]-'a';
  if(!op) {
    dfs(p, idx+1, 1); // 删除
    for(int i = 0; i < 26; ++i) {
      if(son[p][i]) {
        if(i != ch) dfs(son[p][i], idx+1, 1); // 替换
        dfs(son[p][i], idx, 1); // 插入
      }
    }
  }
  if(idx >= s.length()) return;
  if(son[p][ch]) dfs(son[p][ch], idx+1, op);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> s;
    Insert(s);
  }
  while(m--) {
    cin >> s;
    dfs(0, 0, 0);
    if(found) {
      cout << -1 << endl;
      found = 0;
    } else cout << num << endl;
    while(num) vis[visx[num--]] = 0;
  }
  return 0; 
}