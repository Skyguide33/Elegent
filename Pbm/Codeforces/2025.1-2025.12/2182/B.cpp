//2025/12/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a, b; cin >> a >> b;
  int maxa = 0, maxb = 0;
  int k = 1, ta = a, tb = b;
  while(ta >= k) {
    ++maxa;
    ta -= k;
    k <<= 1;
    swap(ta, tb);
  }
  k = 1, ta = b, tb = a;
  while(ta >= k) {
    ++maxb;
    ta -= k;
    k <<= 1;
    swap(ta, tb);
  }
  cout << max(maxa, maxb) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}