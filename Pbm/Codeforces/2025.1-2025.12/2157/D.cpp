//2025/11/25 补题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, l, r; cin >> n >> l >> r;
  vector<int> a(n+1), sgn(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin()+1, a.end());
  int balance = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] < l) sgn[i] = 1, ++balance;
    else if(a[i] > r) sgn[i] = -1, --balance;  
  }
  for(int i = 1, j = n; i <= n; --j, ++i) {
    if(sgn[i] == 0 && balance < 0) sgn[i] = 1, ++balance;
    if(sgn[j] == 0 && balance > 0) sgn[j] = -1, --balance;
  }
  int zeros = 0;
  for(int i = 1; i <= n; ++i) zeros += (sgn[i] == 0);
  for(int i = 1, j = 1; j <= zeros/2; ++i) {
    if(sgn[i] == 0) sgn[i] = 1, ++j;
  }
  for(int i = n, j = 1; j <= zeros/2; --i) {
    if(sgn[i] == 0) sgn[i] = -1, ++j;
  }
  ll ansl = 0, ansr = 0;
  for(int i = 1; i <= n; ++i) {
    if(sgn[i] == 1) ansl += l-a[i], ansr += r-a[i];
    else if(sgn[i] == -1) ansl += a[i]-l, ansr += a[i]-r;
  }
  cout << min(ansl, ansr) << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}