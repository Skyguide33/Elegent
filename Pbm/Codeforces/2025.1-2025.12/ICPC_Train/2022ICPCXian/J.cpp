//2025/11/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n; 
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  if(a[n-1] > 0) cout << 1ll*(a[n-1]+a[n]) << endl;
  else if(a[n] > 0) cout << a[n] << endl;
  else cout << 0 << endl;
  return 0;
}