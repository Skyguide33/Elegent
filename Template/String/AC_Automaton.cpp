//2025/10/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
  int son[26], fail, end;
} t[1000005];
int cnt = 1;

char s[1000005];

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
  int now = 0, ans = 0;
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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) cin >> s, Insert(s);
  getFail();
  cin >> s;
  cout << query(s) << endl;
  return 0;
}