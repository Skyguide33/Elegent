//2025/10/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

struct Node {
  int son[26], end, fail;
} t[N];

int cnt;
char s[N];

void Insert(char *s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!t[now].son[ch]) t[now].son[ch] = cnt++;
    now = t[now].son[ch];
  }
  ++t[now].end;
}

void getFail() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) {
    if(t[0].son[i]) q.push(t[0].son[i]);
  }
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(t[now].son[i]) {
        t[t[now].son[i]].fail = t[t[now].fail].son[i];
        q.push(t[now].son[i]);
      } else t[now].son[i] = t[t[now].fail].son[i];
    }
  }
}

int query(char *s) {
  int ans = 0, now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = t[now].son[ch];
    int tmp = now;
    while(tmp && t[tmp].end != -1) {
      ans += t[tmp].end;
      t[tmp].end = -1;
      tmp = t[tmp].fail;
    }
  }
  return ans;
}

void solve() {
  memset(t, 0, sizeof(t));
  cnt = 1;
  int n; cin >> n;
  while(n--) cin >> s, Insert(s);
  getFail();
  cin >> s;
  cout << query(s) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}