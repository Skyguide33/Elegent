//2025/3/24
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int cnt[N];
struct node{
  int c, f;
  vector<int>child;
} t[N];

#if 0
bool bfs(int x) {
  memset(cnt, 0, sizeof(cnt));
  queue<node> q;
  q.push(t[x]);
  while(q.size()) {
    node now = q.front(); q.pop();
    cnt[now.c]++;
    for(auto i: now.child) {
      q.push(t[i]);
    }
  }
  int num = 0;
  for(int i = 1; i <= 5000; i++) {
    if(num == 0 && cnt[i] > 0) num = cnt[i];
    if(num > 0 && cnt[i] > 0 && num != cnt[i]) return false;
  }
  return true;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> t[i].c >> t[i].f;
    t[t[i].f].child.push_back(i);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(bfs(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
#endif
#if 1

void dfs(int x) {
  for(auto i: t[x].child) dfs(i);
  cnt[t[x].c]++;
  return;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >>  t[i].c >> t[i].f;
    t[t[i].f].child.push_back(i);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    dfs(i);
    int num = cnt[t[i].c], flag = 1;
    for(int j = 1; j <= 5000; j++) {
      if(cnt[j] > 0 && num != cnt[j]) {
        flag = 0;
        break;
      }
    }
    ans += flag;
  }
  cout << ans << endl;
  return 0;
}
#endif