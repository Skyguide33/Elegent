//2025/3/2
#include <iostream>
#include <cmath>
using namespace std;
#define MOD 1000003


int main() {
  long long n, ans = 0, x = -1, p[63];
  cin >> n;
  p[0] = 1;
  for(int i = 1; i < 63; i++) {
    p[i] = p[i-1]*2;
  }
  int m = n;
  for(int i = 62; i >= 0; i--) {
    if(m >= p[i]) {
      x++;
      m -= p[i];
      ans += (int(pow(2,x)) * int(pow(3,i)));
      ans %= MOD;
    }
  }
  long long sum = (n%MOD)*((n+1)%MOD)/2;
  cout << sum-ans << endl;
  return 0;
}