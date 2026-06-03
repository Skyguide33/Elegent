//2025/7/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h[21][21][21];

inline int w(ll a, ll b, ll c) {
  if(a <= 0 || b <= 0 || c <= 0) return 1;
  else if(a > 20 || b > 20 || c > 20) return 1048576;
  else if(h[a][b][c] == 0) {
    if(a < b && b < c) h[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else h[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
  } 
  return h[a][b][c];
}

void solve() {
  ll a, b, c;
  while(scanf("%lld %lld %lld", &a, &b, &c)) {
    if(a == -1 && b == -1 && c == -1) return;
    printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c));
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  clock_t start = clock();
  while(T--) solve();
  clock_t end = clock();
  printf("time = %lfs\n", double(end-start)/CLOCKS_PER_SEC);
  return 0;
}