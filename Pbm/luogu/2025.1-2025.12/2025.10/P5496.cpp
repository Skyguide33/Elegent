//2025/10/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define N 500005

struct Node {
  int len, siz, fail, son[26];
} t[N];
int num = 1;

int s[N], ans, tail, last;

int getfail(int p) {
  while(s[tail] != s[tail-t[p].len-1]) p = t[p].fail;
  return p;
}

void Insert() {
  int father = getfail(last);
  int now = t[father].son[s[tail]];
  if(!now) {
    now = ++num;
    t[now].len = t[father].len+2;
    t[now].fail = t[getfail(t[father].fail)].son[s[tail]];
    t[now].siz = t[t[now].fail].siz+1;
    t[father].son[s[tail]] = now;
  } 
  last = now;
  ans = t[now].siz;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(s, -1, sizeof(s));
  t[1].len = -1;
  t[0].fail = 1;
  char ch;
  while(cin >> ch) {
    s[++tail] = (ch-'a'+ans)%26;
    Insert();
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}