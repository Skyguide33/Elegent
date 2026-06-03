//2025/11/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

ll gcd(ll a, ll b) { 
  return b? gcd(b, a%b): a;
}

// 拓展欧几里得定理
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

// 带模快速幂
ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%mod;
    b = (b*b)%mod;
    p >>= 1; 
  }
  return res;
}

// 逆元
ll mod_inverse(ll a, ll mod) {
  if(0) {
    ll x, y; extend_gcd(a, mod, x, y);
    return (x%mod+mod)%mod;
  } else return fast_power(a, mod-2, mod);
}

// 带模乘法
ll mod_mul(ll a, ll b, ll mod) {
  ll res = 0;
  a %= mod; b %= mod;
  while(b) {
    if(b&1) res = (res+a)%mod;
    a = (a+a)%mod;
    b >>= 1;
  }
  return res;
}

// 带模除法
ll mod_div(ll a, ll b, ll mod) {
  return a%mod*mod_inverse(b, mod)%mod;
}

// 迭代
ll excrt(const ll *a, const ll *m, const int n) {
  ll x, y, a1 = a[1], m1 = m[1];
  ll ans = (a1%m1+m1)%m1;
  for(int i = 2; i <= n; ++i) {
    ll a2 = a[i], m2 = m[i];
    ll a = m1, b = m2, c = (a2-a1%m2+m2)%m2;
    ll d = extend_gcd(a, b, x, y);
    if(c%d) return -1;
    x = mod_mul(x, c/d, b/d);
    ans = a1+x*m1;
    m1 = m2/d*m1;
    ans = (ans%m1+m1)%m1;
    a1 = ans;
  }
  return ans;
}

// Miller-Rabin素性测试 判断单个大数是否为素数
bool witness(ll a, ll n) {
  ll u = n-1;
  int t = 0;
  while(!u&1) u >>= 1, ++t;
  ll x1, x2;
  x1 = fast_power(a, u, n);
  for(int i = 1; i <= t; ++i) {
    x2 = fast_power(x1, 2, n);
    if(x2 == 1 && x1 != 1 && x1 != n-1) return 1;
    x1 = x2;
  }
  if(x1 != 1) return 1;
  return 0;
}

bool miller_rabin(ll n, int s) {
  if(n == 2) return 1;
  else if(n%2 == 0 || n < 2) return 0;
  for(int i = 0; i < s && i < n; ++i) {
    ll a = rand()%(n-1)+1;
    if(witness(a, n)) return 0;
  }
  return 1;
}

// 素数筛(欧拉筛) 筛出2-n内的素数
int prime[N], mpf[N]; // 分别存储第i个素数和i的最小质因数
int eular_sieve(int n) {
  int cnt = 0;
  memset(mpf, 0, sizeof(mpf));
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

// 分解质因数 试除法
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

// 欧拉函数 求单个欧拉函数
ll eular(ll n) {
  ll ans = n;
  for(int i = 2; i*i <= n; ++i) {
    if(n%i == 0) {
      ans = ans/i*(i-1);
      while(n%i == 0) n /= i;
    }
  }
  if(n != 1) ans = ans/n*(n-1);
  return ans;
}

// 线性筛(欧拉筛),求1-n的欧拉函数
int phi[N]; // int prime[N];
void get_phi(int n) {
  phi[1] = 1;
  int cnt = 0;
  for(int i = 2; i <= n; ++i) {
    if(!mpf[i]) {
      mpf[i] = i;
      prime[cnt++] = i;
      phi[i] = i-1;
    }
    for(int j = 0; j < cnt; ++j) {
      if(i*prime[j] > n) break;
      mpf[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) {
        phi[i*prime[j]] = phi[i]*prime[j];
        break;
      }
      phi[i*prime[j]] = phi[i]*phi[prime[j]];
    }
  }
}

// 组合数 
ll fac[N], inv[N]; // 阶乘序列(取模)和对应的逆
void c_init(int n, int mod) {
  fac[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod_inverse(fac[i], mod);
  } 
}
int C(int n, int m, int mod) {
  return (fac[n]*inv[m]%mod*inv[n-m]%mod)%mod;
}

// 卢卡斯定理 (要求mod为素数且值较小<1e7)
// int fac[N];
void lucas_init(int mod) {
  fac[0] = 1;
  for(int i = 1; i <= mod; ++i) {
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod_inverse(fac[i], mod);
  } 
}

ll C(ll n, ll m, ll mod) {
  if(m > n) return 0;
  return fac[n]*mod_inverse(fac[m], mod)%mod*mod_inverse(fac[n-m], mod)%mod;
}

ll Lucas(ll n, ll m, ll mod) {
  if(m == 0) return 1;
  return C(n%mod, m%mod, mod)*Lucas(n/mod, m/mod, mod)%mod;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int mod = 16127;
  c_init(44, mod);
  cout << 7669339132%mod << endl;
  cout << C(44, 11, mod) << endl;
  return 0;
}