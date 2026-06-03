//2025/11/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005

// 素数筛(欧拉筛) 筛出2-n内的素数
int prime[N], mpf[N]; // 分别存储第i个素数和i的最小质因数
int eular_sieve(int n) {
  int cnt = 0;
  for(int i = 2; i <= n; ++i) {
    if(!mpf[i]) {
      prime[cnt++] = i;
      mpf[i] = i;
    }
    for(int j = 0; j < cnt; ++j) {
      if(i*prime[j] > n) break;
      mpf[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break;
    }
  }
  return cnt; // 返回素数的个数, prime下标从0开始
}

ll p[20], c[40]; // 从小到大记录n的质因数和个数(n < 1e16)
int factor(ll n) {
  int cnt = 0, t = sqrt(n);
  for(int i = 0; prime[i] <= t; ++i) {
    if(n%prime[i] == 0) {
      p[++cnt] = prime[i], c[cnt] = 0;
      while(n%prime[i] == 0) n /= prime[i], ++c[cnt];
    }
  }
  if(n > 1) p[++cnt] = n, c[cnt] = 1;
  return cnt; // 返回不同质因数的个数, 遍历下标从1开始
}

void solve() {
  ll n; cin >> n;
  int cnt = factor(n);
  ll mul = 1;
  for(int i = 1; i <= cnt; ++i) {
    mul *= 2*c[i]+1;
  }
  cout << (mul-1)/2+1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  eular_sieve(N);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}