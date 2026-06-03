//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dir[128][128], dge[128], cnt;
char ans[2005];

void eular(int u) {
  for(int v = 65; v < 128; ++v) {
    if(dir[u][v]) {
      --dir[u][v];
      --dir[v][u];
      eular(v);
    }
  }
  ans[++cnt] = u;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    char x, y; cin >> x >> y;
    int u = x, v = y;
    ++dir[u][v];
    ++dir[v][u];
    ++dge[u];
    ++dge[v];
  }
  int cnt = 0;
  for(int i = 65; i < 128; ++i) {
    if(dge[i]%2) ++cnt;
  } 
  if(cnt != 0 && cnt != 2) cout << "No Solution" << endl;
  else {
    for(int i = 65; i < 128; ++i) {
      if((cnt && dge[i]%2) || (!cnt && dge[i])) {
        eular(i);
        break;
      }
    }
    for(int i = n+1; i >= 1; --i) cout << ans[i];
    cout << endl;
  }
  return 0;
}