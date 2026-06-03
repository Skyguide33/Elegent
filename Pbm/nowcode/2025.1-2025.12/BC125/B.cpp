//2025/12/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  while(q--) {
    int k, x; cin >> k >> x;
    if(a[k] < x) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}