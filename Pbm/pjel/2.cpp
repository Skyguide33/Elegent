//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a = 1, b = 2;
  ll ans = 0;
  while(b <=4000000) {
    if(b%2 == 0) ans += b;
    a += b;
    swap(a, b);
  }
  cout << ans << endl;
  return 0;
}

// 4613732