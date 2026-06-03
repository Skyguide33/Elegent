//2025/4/1
#include <bits/stdc++.h>
using namespace std;

long long a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    memset(a, 0, sizeof(a));
    int n; cin >> n;
    long long sum = 0, maxa = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      maxa = max(maxa, a[i]);
      if(sum == maxa*2) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}