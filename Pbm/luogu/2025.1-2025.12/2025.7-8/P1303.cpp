//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 6000

typedef complex<double> cp;
double pi = acos(-1);

cp a[N], b[N];
int rev[N], ans[N];
char s1[N], s2[N];

void init(int k) {
  int len = 1<<k;
  for(int i = 0; i < len; ++i)
    rev[i] = (rev[i>>1]>>1) | ((1&i)<<(k-1));
}

void fft(cp *a, int n, int flag) {
  for(int i = 0; i < n; ++i)
    if(i < rev[i]) swap(a[i], a[rev[i]]);
  for(int h = 1; h < n; h <<= 1) {
    cp wn = exp(cp(0, flag*pi/h));
    for(int j = 0; j < n; j += h*2) {
      cp w(1, 0);
      for(int k = j; k < j+h; ++k) {
        cp x = a[k];
        cp y = w*a[k+h];
        a[k] = x+y;
        a[k+h] = x-y;
        w *= wn;
      }
    }
  }
  if(flag == -1)
    for(int i = 0; i < n; ++i) a[i] /= n;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s1 >> s2;
  int len1 = strlen(s1), len2 = strlen(s2), maxn = max(len1, len2);
  for(int i = 0; i < len1; ++i) a[i] = (double)(s1[len1-i-1]-'0');
  for(int i = 0; i < len2; ++i) b[i] = (double)(s2[len2-i-1]-'0');
  int k = 1, s = 2;
  while((1<<k) < 2*maxn-1) ++k, s <<= 1;
  init(k);
  fft(a, s, 1);
  fft(b, s, 1);
  for(int i = 0; i < s; ++i) a[i] *= b[i];
  fft(a, s, -1);
  for(int i = 0; i < s; ++i) {
    ans[i] += (int)(a[i].real()+0.5);
    ans[i+1] += ans[i]/10;
    ans[i] %= 10;
  }
  while(s > -1 && !ans[s]) --s;
  if(s == -1) cout << '0';
  else {
    for(int i = s; i >= 0; --i) cout << ans[i];
  }
  cout << endl;
  return 0;
}