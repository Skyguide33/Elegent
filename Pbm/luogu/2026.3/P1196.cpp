//2026/3/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 30005

int s[30005], ans[500005], rear[30005], back[30005], num[30005], tail;
pair<int, int> q[500005];


int find_set(int x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

void merge_set(int x, int y) {
  int rx = find_set(x), ry = find_set(y);
  s[rx] = ry;
  back[rear[ry]] = rx;
  rear[ry] = rear[rx];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 30000; ++i) s[i] = i, rear[i] = i;
  int T; cin >> T;
  while(T--) {
    char op; cin >> op;
    int x, y; cin >> x >> y;
    if(op == 'M') merge_set(x, y);
    else {
      q[++tail] = {x, y};
      if(find_set(x) != find_set(y)) ans[tail] = -1;
    }
  }
  for(int i = 1; i <= 30000; ++i) {
    if(i == s[i]) {
      int idx = 0, now = i;
      while(now) {
        num[now] = ++idx;
        now = back[now];
      }
    }
  }
  for(int i = 1; i <= tail; ++i) {
    if(ans[i] != -1) {
      auto [x, y] = q[i];
      ans[i] = abs(num[x]-num[y])-1;
    }
  }
  for(int i = 1; i <= tail; ++i) cout << ans[i] << endl;
  return 0;
}