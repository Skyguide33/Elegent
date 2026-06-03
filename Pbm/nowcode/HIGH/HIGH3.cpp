//2026/5/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n; cin >> n;
  int n2 = 0, n5 = 0, p = 1;
  for(int i = 1; i <= n; ++i) {
    ll tt = i;
    while(tt%5 == 0) {
      tt /= 5;
      ++n5;
    }
    while(tt%2 == 0) {
      tt /= 2;
      ++n2;
    }
    p = p*tt%10;
  }
  for(int i = 1; i <= n2-n5; ++i) {
    p = p*2%10;
  }
  cout << p << endl;
  return 0;
}