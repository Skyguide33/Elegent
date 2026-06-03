//2025/7/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int prime[1231];
int year[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int m[39], y[55158], totm, toty, t, totp;
char s[9];

inline bool is_prime(const int& x) {
  int tag = sqrt(x);
  for(int i = 0; prime[i] <= tag; ++i) if(x%prime[i] == 0) return 0;
  return 1;
} 

int main() {
  memset(prime, 0x3f, sizeof(prime));
  cin.tie(0) -> sync_with_stdio(0);
  prime[totp++] = 2;
  for(int i = 2; i <= 10000; ++i) {
    if(is_prime(i)) prime[totp++] = i;
  }
  for(int i = 1; i <= 12; ++i) {
    for(int j = 0; prime[j] <= year[i]; ++j) {
      t = i*100 + prime[j];
      if(is_prime(t)) m[++totm] = t;
    }
  }
  for(int i = 4; i <= 9996; i += 4) {
    t = i*10000 + 229;
    if((i%100 != 0 || i%400 == 0) && is_prime(t)) y[++toty] = t;
  }
  for(int i = 1; i <= 9999; ++i) {
    for(int j = 1; j <= totm; ++j) {
      t = i*10000 + m[j];
      if(is_prime(t)) y[++toty] = t;
    }
  }
  int T = 1; cin >> T;
  while(T--) {
    cin >> s;
    int ans = 0;
    bool flag;
    for(int i = 1; i <= toty; ++i) {
      t = y[i]; flag = 1;
      for(int j = 7; j >= 0 && flag; --j, t /= 10) {
        if(t%10 != s[j]-'0' && s[j] != '-') flag = 0;
      }
      ans += flag;
    }
    cout << ans << endl;
  }
  return 0;
}