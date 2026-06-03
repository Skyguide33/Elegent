//2025/5/27 rewrite 5/28
#include <bits/stdc++.h>
using namespace std;
#define N 200005

int m, n, n2;

int go[N*2][19], res[N];
struct W{ int id, L, R; } w[N*2]; 

bool cmp(W x, W y) { return x.L < y.L; }

void init() {
  int nxt = 1;
  for(int i = 1; i <= n2; ++i) {
    while(nxt <= n2 && w[i].R >= w[nxt].L) ++nxt;
    go[i][0] = nxt-1;
  } 
  for(int i = 1; (1<<i) <= n; ++i) {
    for(int s = 1; s <= n2; ++s) {
      go[s][i] = go[go[s][i-1]][i-1];
    }
  }
}

void getans(int x) {
  int len = w[x].L + m, cur = x, ans = 1;
  for(int i = log2(n2); i >= 0; --i) {
    int pos = go[cur][i];
    if(pos && w[pos].R < len) {
      ans += (1<<i);
      cur = pos;
    }
  }
  res[w[x].id] = ans+1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    w[i].id = i; cin >> w[i].L >> w[i].R;
    if(w[i].R < w[i].L) w[i].R += m;
  }
  sort(w+1, w+n+1, cmp);
  n2 = n;
  for(int i = 1; i <= n; ++i) {
    w[++n2] = w[i]; w[n2].L += m; w[n2].R += m;
  }
  init();
  for(int i = 1; i <= n; ++i) getans(i);
  for(int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
  return 0;
}