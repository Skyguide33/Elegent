//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll opt(ll a, ll b) {
  if(a == 0 && b == 0) return 0;
  ll t = __gcd(a, b);
  return min(opt(a-t,b), opt(a,b-t))+1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout << __gcd(43, 98) << endl;
  return 0;
}