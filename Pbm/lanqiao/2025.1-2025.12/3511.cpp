//2025/4/11
#include <bits/stdc++.h>
using namespace std;

struct Plane {
  int t, d, l;
} a[11];

bool issafe, isld[11];

bool cmp(Plane x, Plane y) { return x.d < y.d; }

int N; 

void dfs(int now, int ldd) {
  if(issafe == 1 || ldd == N) {
    issafe = 1;
    return;
  }
  for(int i = 1; i <= N; i++) {
    if(!isld[i] && a[i].d >= now) {
      isld[i] = 1;
      dfs(max(now,a[i].t)+a[i].l, ldd+1);
      isld[i] = 0;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    issafe = 0;
    memset(isld, 0, sizeof(isld));
    cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> a[i].t >> a[i].d >> a[i].l;
      a[i].d += a[i].t;
    }
    dfs(0, 0);
    if(issafe) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}