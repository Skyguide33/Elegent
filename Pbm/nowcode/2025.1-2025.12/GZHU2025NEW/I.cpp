//2026/3/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005], b[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, tt; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> tt, ++a[tt];
  for(int i = 1; i <= m; ++i) cin >> tt, ++b[tt];
  ll score = 0;
  for(int i = 1; i <= 1000000; ++i) {
    if(a[i]&b[i]) score += i; 
  }
  if(n > m) {
    cout << score << " 0" << endl;
  } else cout << "0 " << score << endl;
  return 0;
}