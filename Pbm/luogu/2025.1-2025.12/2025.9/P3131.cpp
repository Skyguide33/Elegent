//2025/9/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2], b[7];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, ans = 0; cin >> n;
  for(int i = 1; i < 7; ++i) b[i] = 50001;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i&1]; a[i&1] = (a[i&1]+a[(i-1)&1])%7;
    if(b[a[i&1]] == 50001) b[a[i&1]] = i; 
    ans = max(ans, i-b[a[i&1]]);
  }
  cout << ans << endl;
  return 0;
}