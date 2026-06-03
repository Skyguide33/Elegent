//2025/2/12
#include <iostream>
using namespace std;

#if 0
// 0 1 2 3 4 5 6 7 8 9 + =
// 6 2 5 5 4 5 6 3 7 6 2 2
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int GetN(int n) {
  int res = 0;
  if(n == 0) return 6;
  do {
    res += num[n%10];
    n /= 10;
  } while(n);
  return res;
}
int main() {
  int n, ans = 0;
  cin >> n;
  for(int i = 0; i <= 41; i++) {
    int Ln = GetN(i);
    for(int j = i; j <= 711; j++) {
      int Rn = GetN(j);
      int Sn = GetN(i+j);
      if(n-4 == Ln+Rn+Sn) {
        if(i != j) ans += 2;
        else ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
#endif

#if 1
int main() {
  int n, anss[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 8, 9, 6, 9, 29, 39, 38, 65, 88, 128};
  cin >> n;
  cout << anss[n] << endl;
  return 0;
}
#endif