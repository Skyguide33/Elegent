//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll p[20], c[20];

int factor(ll n) {
  int tt = sqrt(n), cnt = 0;
  for(int i = 2; i <= tt; ++i) {
    if(n%i == 0) {
      p[++cnt] = i;
      while(n%i == 0) n /= i, ++c[cnt];
    }
  }
  if(n > 1) p[++cnt] = n, c[cnt] = 1;
  return cnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int cnt = factor(600851475143);
  // for(int i = 1; i <= cnt; ++i) {
  //   cout << p[i] << ' ' << c[i] << "  ";
  // }
  // cout << endl;
  cout << p[cnt] << endl;
  return 0;
}

// 6857