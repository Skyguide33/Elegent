//2025/5/26
#include <bits/stdc++.h>
using namespace std;

int n, m, cl[1000005], cr[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  int min_n = 1000000, max_n = 1;
  while(n--) {
    int l, r; cin >> l >> r;
    int len = r - l;
    min_n = min(min_n, l); max_n = max(max_n, r);
    ++cl[l+len/2]; ++cr[r-len/2];
  }
  for(int i = min_n; i <= 1000000; ++i) {
    cl[i] += cl[i-1]; 
    cr[i] += cr[i-1]; 
  }
  while(m--) {
    int l, r; cin >> l >> r;
    cout << cr[r] - cl[l-1] << endl;
  }
  return 0;
}