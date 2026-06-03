//2025/8/
#include <iostream>
#include <numeric>
using namespace std;
#define ll long long
#define endl '\n'

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

ll mod[33];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  mod[0] = 1;
  for(int i = 1; i <= 32; ++i) mod[i] = mod[i-1]*2;
  ll a, b, c, k, x, y, num, g, t;
  while(1) {
    cin >> a >> b >> c >> k;
    if(k == 0) break;
    num = b-a;
    g = extend_gcd(c, mod[k], x, y);
    if(num % g) cout << "FOREVER" << endl;
    else {
      x *= num/g;
      t = mod[k]/g;
      cout << (x%t+t)%t << endl;
    }
  }
  return 0;
}