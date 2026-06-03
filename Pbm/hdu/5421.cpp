//2025/10/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 300005

int s[N];
struct Node {
  int len, fail, son[26], siz;
  void init(int _len) {
    memset(son, 0, sizeof(son));
    fail = siz = 0;
    len = _len;
  }
} tree[N];

ll num, last[2], ans, L, R;

void init() {
  last[0] = last[1] = 0;
  ans = 0; num = 1;
  L = 1e5+8; R = 1e5+7;
  tree[0].init(0);
  memset(s, -1, sizeof(s));
  tree[1].init(-1);
  tree[0].fail = 1; 
}

int getfail(int p, int d) {
  if(d) while(s[R-tree[p].len-1] != s[R]) p = tree[p].fail;
  else while(s[L+tree[p].len+1] != s[L]) p = tree[p].fail;
  return p;
}

void Insert(int x, int d) {
  if(d) s[++R] = x;
  else s[--L] = x;
  int father = getfail(last[d], d);
  int now = tree[father].son[x];
  if(!now) {
    now = ++num;
    tree[now].init(tree[father].len+2);
    tree[now].fail = tree[getfail(tree[father].fail, d)].son[x];
    tree[now].siz = tree[tree[now].fail].siz+1;
    tree[father].son[x] = now;
  }
  last[d] = now;
  if(R-L+1 == tree[now].len) last[d^1] = now; 
  ans += tree[now].siz;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, op; char c;
  while(cin >> n) {
    init();
    while(n--) {
      cin >> op;
      if(op == 1) cin >> c, Insert(c-'a', 0);
      else if(op == 2) cin >> c, Insert(c-'a', 1);
      else if(op == 3) cout << num-1 << endl;
      else cout << ans << endl;
    }
  }
  return 0;
}