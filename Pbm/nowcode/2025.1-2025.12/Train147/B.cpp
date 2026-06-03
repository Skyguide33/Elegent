//2025/12/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  auto b = a;
  sort(b.begin()+1, b.end());
  bool flag = 1;
  for(int i = 1; i <= n; ++i) {
    ll num = 1ll*a[i]*b[i], tt = sqrt(num);
    if(tt*tt != num) {
      flag = 0;
      break;
    }
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}