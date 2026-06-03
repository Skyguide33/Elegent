//2026/5/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005];

void solve() {
  ll n, x, y; cin >> n >> x >> y;
  ll cnt1 = 0, cnt0 = 0, subx = 0, suby = 0;
  for(int i = 1; i <= n; ++i) {
    char tt; cin >> tt;
    a[i] = tt-'0';
    if(a[i] == 1) ++cnt1;
    else if(a[i] == 0) ++cnt0;
    if(i == (x+y)%n) {
      subx += cnt0;
      suby += cnt1;
    }
  }
  ll epoch = (x+y)/n;
  subx += cnt0*epoch;
  suby += cnt1*epoch;
  x -= subx; y -= suby;
  int cnt2 = n-cnt1-cnt2;
  auto check = [&](int k)->bool {
    
  };
  int l = -1, r = cnt2+1;
  while(l < r) {

  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}