//2026/1/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int mid  = (n+1)/2, low = 0, upp = 0;
  if((n+1)/2%2) low = mid-mid/2, upp = mid+mid/2;
  else low = mid-mid/2+1, upp = mid+mid/2;
  for(int i = 1; i <= n; ++i) {
    if(a[i] < low || a[i] > upp) cout << a[i] << ' ';
    else cout << mid << ' ';
  }
  cout << endl;
  return 0;
}