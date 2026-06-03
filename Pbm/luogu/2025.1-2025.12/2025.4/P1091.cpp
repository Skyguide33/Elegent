//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int a[105], dpl[105], dpr[105]; 
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    dpl[i] = 1;
    for(int j = 1; j < i; j++) {
      if(a[j] < a[i]) dpl[i] = max(dpl[i], dpl[j] + 1);
    }
  }
  for(int i = n; i >= 1; i--) {
    dpr[i] = 1;
    for(int j = n; j > i; j--) {
      if(a[j] < a[i]) dpr[i] = max(dpr[i], dpr[j] + 1);
    }
  }
  int ans = n;
  for(int i = 1; i <= n; i++) {
    ans = min(ans, n-(dpl[i]+dpr[i]-1));
  }
  cout << ans << endl;
  return 0;
}