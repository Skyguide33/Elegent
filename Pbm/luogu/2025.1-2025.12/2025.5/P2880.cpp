//2025/5/28
#include <bits/stdc++.h>
using namespace std;
#define N 500005

int n, q, a[N], max_h[N][25], min_h[N][25], LOG2[N];

void init() {
  LOG2[0] = -1;
  for(int i = 1; i <= n; ++i) {
    LOG2[i] = LOG2[i>>1]+1;
    max_h[i][0] = a[i]; min_h[i][0] = a[i];
  }
  for(int i = 1; i <= log2(n); ++i) {
    for(int s = 1; s <= n; ++s) {
      max_h[s][i] = max(max_h[s][i-1], max_h[s+(1<<(i-1))][i-1]);
      min_h[s][i] = min(min_h[s][i-1], min_h[s+(1<<(i-1))][i-1]);
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  init();
  while(q--) {
    int l, r; cin >> l >> r;
    int len = LOG2[r-l+1];
    int h_max = max(max_h[l][len], max_h[r+1-(1<<len)][len]);
    int h_min = min(min_h[l][len], min_h[r+1-(1<<len)][len]);
    cout << h_max-h_min << endl;
  }
  return 0;
}