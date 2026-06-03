//2025/10/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
  int son[26], end, fail;
} t[10505];
int cnt;

char s[1000005];
map<int, string> mp;
int tt[10505];

void Insert(char *s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!t[now].son[ch]) t[now].son[ch] = cnt++;
    now = t[now].son[ch];
  }
  t[now].end = 1;
  mp[now] = s;
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

void query(char *s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = t[now].son[ch];
    int tmp = now;
    while(tmp) {
      if(t[tmp].end) ++tt[tmp];
      tmp = t[tmp].fail;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  while(1) {
    int n; cin >> n;
    if(!n) break;
    memset(t, 0, sizeof(t));
    memset(tt, 0, sizeof(tt));
    mp.clear();
    cnt = 1;
    while(n--) cin >> s, Insert(s);
    getFail();
    cin >> s; query(s);
    int times = 0;
    for(auto &[x, y]: mp) times = max(times, tt[x]);
    cout << times << endl;
    for(auto &[x, y]: mp) {
      if(tt[x] == times) cout << y << endl;
    }
  }
  return 0;
}