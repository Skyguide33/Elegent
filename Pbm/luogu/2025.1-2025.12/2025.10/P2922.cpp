//2025/10/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
  int son[2], num, isend;
} t[200005];

int cnt, a[10005];

void Insert(int len) {
  int now = 0;
  for(int i = 1; i <= len; ++i) {
    cin >> a[i];
    if(t[now].son[a[i]] == 0) t[now].son[a[i]] = ++cnt;
    now = t[now].son[a[i]];
    ++t[now].num;
  }
  --t[now].num;
  ++t[now].isend;
}

int Find(int len) {
  int now = 0, res = 0;
  for(int i = 1; i <= len; ++i) cin >> a[i];
  for(int i = 1; i <= len; ++i) {
    if(t[now].son[a[i]] == 0) {
      return res;
    }
    now = t[now].son[a[i]];
    res += t[now].isend;
  }
  return res+t[now].num;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, n; cin >> m >> n;
  while(m--) {
    int b; cin >> b;
    Insert(b);
  }
  while(n--) {
    int c; cin >> c;
    cout << Find(c) << endl;
  }
  return 0;
}