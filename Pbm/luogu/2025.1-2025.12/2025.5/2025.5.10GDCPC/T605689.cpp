//2025/5/10
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  long long n; cin >> n;
  long long ans = 1ll * (1+n)*n/2;
  long long n2 = n/2;
  long long max2 = n/2*2;
  long long n5 = n/5;
  long long max5 = n/5*5;
  long long n10 = n/10;
  long long max10 = n/10*10;
  ans -= 1ll * (2+max2)*n2/2 + 1ll * (5+max5)*n5/2 - 1ll * (10+max10)*n10/2;
  cout << ans << endl;
  return 0;
}