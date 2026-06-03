//2026/5/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[16], len;

void solve() {
  ll n; cin >> n;
  int cnt1 = 0, cnt2 = 0;
  ll tt = n;
  while(tt) {
    int num = tt%10;
    if(num && n%num) ++cnt1;
    else ++cnt2;
    tt /= 10;
  }
  if(cnt1 == 0) cout << 'G' << endl;
  else if(cnt2 == 0) cout << 'S' << endl;
  else cout << 'H' << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}