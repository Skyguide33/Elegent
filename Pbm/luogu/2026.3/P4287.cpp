//2026/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005

struct node {
  int len, siz, fail, trans, son[26];
} tri[N];

int s[N], idx, last, cnt = 1;

int getfail(int p) {
  while(s[idx] != s[idx-tri[p].len-1]) p = tri[p].fail; 
  return p;
}

int gettrans(int p) {
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
    if(tri[now].len <= 2) tri[now].trans = tri[now].fail;
    else {
      int tran_fa = tri[father].trans;
      while((tri[tran_fa].len+2)*2 > tri[now].len) tran_fa = tri[tran_fa].fail;
      tri[now].trans = tri[gettrans(tran_fa)].son[s[idx]];
    }
    tri[father].son[s[idx]] = now;
  }
  last = now;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  s[0] = -1;
  tri[1].len = -1;
  tri[0].fail = tri[0].trans = 1;
  int n; cin >> n;
  char ch; 
  for(int i = 1; i <= n; ++i) {
    cin >> ch;
    s[++idx] = ch-'a';
    Insert();
  }
  int ans = 0;
  for(int i = 2; i <= cnt; ++i) {
    if(tri[i].len%4 == 0 && tri[tri[i].trans].len*2 == tri[i].len) {
      ans = max(ans, tri[i].len);
    }
  }
  cout << ans << endl;
  return 0;
}