//2025/9/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int ans = (n+1)/2*n;
  if(!(n&1)) ans += n/2;
  cout << ans << endl;
  for(int i = n; i >= 1; --i) cout << i << ' ';
  cout << endl;
  return 0;
}