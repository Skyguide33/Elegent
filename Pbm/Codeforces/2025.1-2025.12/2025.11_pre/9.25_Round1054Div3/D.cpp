//2025/9/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[200005];
ll disa[200005], disb[200005];

void solve() {
  int n; cin >> n;
  cin >> s;
  ll cnta = 0, cntb = 0;
  for(int i = 0; i < n; ++i) {
    disa[i] = disb[i] = 0;
  } 
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'a') {
      disa[i] = i-cnta;
      ++cnta;
    } else {
      disb[i] = i-cntb;
      ++cntb;
    }
  }
  cnta = n-1, cntb = n-1;
  for(int i = n-1; i >= 0; --i) {
    if(s[i] == 'a') {
      disa[i] = min(disa[i], cnta-i);
      --cnta;
    } else {
      disb[i] = min(disb[i], cntb-i);
      --cntb;
    }
  }
  ll ansa = 0, ansb = 0;
  for(int i = 0; i < n; ++i) {
    ansa += disa[i];
    ansb += disb[i];
  }
  cout << min(ansa, ansb) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}