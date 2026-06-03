//2025/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

int tr[N][26], fail[N], cnt, ed[N];
char s[1000005];

inline void Insert() { 
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!tr[now][ch]) tr[now][ch] = ++cnt;
    now = tr[now][ch];
  }
  ++ed[now];
}

inline void Build() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) 
    if(tr[0][i]) q.push(tr[0][i]);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(tr[now][i]) {
        fail[tr[now][i]] = tr[fail[now]][i];
        q.push(tr[now][i]);
      } else tr[now][i] = tr[fail[now]][i];
    }
  }
}

inline int query(char *s) {
  int now = 0, ans = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    int tmp = now = tr[now][ch];
    while(tmp && ed[tmp] != -1) {
      ans += ed[tmp];
      ed[tmp] = -1;
      tmp = fail[tmp];
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) cin >> s, Insert();
  Build();
  cin >> s;
  cout << query(s) << endl;
  return 0;
}