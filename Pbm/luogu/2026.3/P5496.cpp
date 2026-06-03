//2026/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005

struct node {
  int len, siz, fail, son[26];
} tri[N];

int s[N], ans, idx, last, cnt = 1;

int getfail(int p) {
  while(s[idx] != s[idx-tri[p].len-1]) p = tri[p].fail;
  return p;
}

void Insert() {
  int father = getfail(last);
  int now = tri[father].son[s[idx]];
  if(!now) {
    now = ++cnt;
    tri[now].len = tri[father].len+2;
    tri[now].fail = tri[getfail(tri[father].fail)].son[s[idx]];
    tri[now].siz = tri[tri[now].fail].siz+1;
    tri[father].son[s[idx]] = now;
  }
  last = now;
  ans = tri[now].siz;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  s[0] = -1;
  tri[1].len = -1;
  tri[0].fail = 1;
  char ch; 
  while(cin >> ch) {
    s[++idx] = (ch-'a'+ans)%26;
    Insert();
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}