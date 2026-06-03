//2025/10/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 300005

struct Node {
  int len, num, fail, son[26];
} t[N];
int s[N], cnt = 1, last, tail;

int getfail(int p) {
  while(s[tail] != s[tail-t[p].len-1]) p = t[p].fail;
  return p;
}

void Insert() {
  int ch = s[tail];
  int father = getfail(last);
  int now = t[father].son[ch];
  if(!now) {
    now = ++cnt;
    t[now].len = t[father].len+2;
    t[now].fail = t[getfail(t[father].fail)].son[ch];
    t[father].son[ch] = now;
  }
  ++t[now].num;
  last = now;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  t[1].len = -1;
  t[0].fail = 1;
  memset(s, -1, sizeof(s));
  char ch;
  while(cin >> ch) {
    s[++tail] = ch-'a';
    Insert();
  }
  for(int i = cnt; i > 1; --i) {
    t[t[i].fail].num += t[i].num;
  }
  ll ans = 0;
  for(int i = 2; i <= cnt; ++i) ans = max(ans, 1ll*t[i].len*t[i].num);
  cout << ans << endl;
  return 0;
}