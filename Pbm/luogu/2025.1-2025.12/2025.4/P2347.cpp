//2025/4/19
#include <bits/stdc++.h>
using namespace std;

bool h[1002];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  h[0] = 1;
  int a[7], w[7] = {0, 1, 2, 3, 5, 10, 20};
  for(int i = 1; i <= 6; ++i) cin >> a[i];
  for(int i = 1; i <= 6; ++i) 
    for(int j = 1; j <= a[i]; ++j) 
      for(int k = 1000; k >= 1; --k) 
        if(!h[k]) h[k] = h[k-w[i]];
  int ans = 0;
  for(int i = 1; i <= 1000; ++i) ans += h[i];
  cout << "Total=" << ans << endl;
  return 0;
}