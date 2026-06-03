//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct op {
  int a, b;
} s[602];

int dir[27][27], in[27], vis[27], n, state, topo[27], res[27], tpcnt; // 1 

bool check(int x) {
  // cout << "x=" << x << endl;
  for(int i = 0; i <= n; ++i) {
    in[i] = 0; vis[i] = 0;
    for(int j = 0; j <= n; ++j) {
      dir[i][j] = 0;
    }
  }
  for(int i = 1; i <= x; ++i) {
    if(!dir[s[i].a][s[i].b]) {
      dir[s[i].a][s[i].b] = 1;
      ++in[s[i].b];
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(!in[i]) {
      dir[0][i] = 1;
      in[i] = 1;
    }
  }
  queue<int> q;
  q.push(0);
  tpcnt = -1;
  bool flag = 0;
  while(!q.empty()) {
    int now = q.front(); q.pop(); // cout << "pop " << char(now+'A'-1) << "  ";
    topo[++tpcnt] = now;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
      if(dir[now][i]) {
        --in[i];
        if(!vis[i] && !in[i]) {
          if(cnt) flag = 1;
          ++cnt;
          vis[i] = 1;
          q.push(i);
          // cout << "push " << char(i+'A'-1) << "  ";
        }
      }
    }
    // cout << endl;
  }
  // cout << endl;
  for(int i = 1; i <= n; ++i) {
    if(in[i]) {
      state = 1;
      return 1;
    }
  }
  if(flag) return 0;
  for(int i = 1; i <= n; ++i)  res[i] = topo[i];
  state = 2;
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  int l = 1, r = m+1;
  for(int i = 1; i <= m; ++i) {
    char a, tp, b; cin >> a >> tp >> b;
    s[i] = {a-'A'+1, b-'A'+1};
    if(s[i].a == s[i].b) {
      r = i;
      state = 1;
    }
    // cout << format("s[{0}]=[{1}, {2}]\n", i, s[i].a, s[i].b);
  }
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  // for(int i = 1; i <= tpcnt; ++i) cout << topo[i] << ' ';
  // cout << ".\n";
  if(l == m+1) cout << "Sorted sequence cannot be determined." << endl;
  else if(state == 1) cout << format("Inconsistency found after {0} relations.", l) << endl;
  else {
    cout << "Sorted sequence determined after " << l << " relations: ";
    for(int i = 1; i <= n; ++i) cout << char(res[i]+'A'-1);
    cout << ".\n";
  }
  return 0;
}