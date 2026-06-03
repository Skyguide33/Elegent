//2025/4/9
#include <bits/stdc++.h>
using namespace std;

long long r[1000005], b[1000005];

struct cust {
  int d, s, t;
} c[1000005];

bool cmp(cust x, cust y) { return x.s < y.s; };

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> c[i].d >> c[i].s >> c[i].t;
  }
  int minc = 1, maxc = n+1, midc = minc + (maxc-minc) / 2;
  while(minc < maxc) {
    memset(b, 0, sizeof(b));
    bool over = 0;
    for(int i = 1; i <= midc; i++) {
      b[c[i].s] += c[i].d; b[c[i].t+1] -= c[i].d;
    }
    for(int i = 1; i <= n; i++) {
      b[i] += b[i-1];
      if(b[i] > r[i]) {
        over = 1;
        break;
      }
    }
    if(over) maxc = midc;
    else minc = midc+1;
    midc = minc + (maxc-minc) / 2;
  }
  if(midc == n+1) cout << 0 << endl;
  else cout << -1 << endl << midc << endl;
  return 0;
}