// 2025/8/29 - 修改為 10000 進制的 FFT 高精度乘法
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 2000005
#define BASE 10000        // 10000 進制
#define BASE_DIGITS 4     // 每位的數字位數

typedef complex<double> cp;
double pi = acos(-1);

cp a[N], b[N];
int rev[N];
ll ans[N];                // 改為 long long 存儲
char s1[N], s2[N];

// 初始化反轉數組
void init(int k) {
  int len = 1 << k;
  for(int i = 0; i < len; ++i)
    rev[i] = (rev[i>>1]>>1) | ((1&i)<<(k-1));
}

// FFT 核心算法
void fft(cp *a, int n, int flag) {
  for(int i = 0; i < n; ++i) {
    if(i < rev[i]) swap(a[i], a[rev[i]]);
  }
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
  if(flag == -1) {
    for(int i = 0; i < n; ++i) a[i] /= n;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s1 >> s2;
  int len1 = strlen(s1), len2 = strlen(s2);
  
  // 初始化數組
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(ans, 0, sizeof(ans));
  
  int n1 = 0, n2 = 0;
  
  // 將第一個數轉換為 10000 進制數組（從最低位開始）
  for(int i = len1; i > 0; i -= BASE_DIGITS) {
    int start = max(0, i - BASE_DIGITS);
    int digit_len = i - start;
    ll val = 0;
    
    // 計算這 4 位數字的值
    for(int j = start; j < i; ++j) {
      val = val * 10 + (s1[j] - '0');
    }
    a[n1++] = val;
  }
  
  // 將第二個數轉換為 10000 進制數組
  for(int i = len2; i > 0; i -= BASE_DIGITS) {
    int start = max(0, i - BASE_DIGITS);
    int digit_len = i - start;
    ll val = 0;
    
    for(int j = start; j < i; ++j) {
      val = val * 10 + (s2[j] - '0');
    }
    b[n2++] = val;
  }
  
  int maxn = max(n1, n2);
  int k = 1, s = 2;
  // 計算 FFT 需要的長度（2 的冪）
  while((1<<k) < 2*maxn-1) ++k, s <<= 1;
  
  init(k);
  fft(a, s, 1);
  fft(b, s, 1);
  for(int i = 0; i < s; ++i) a[i] *= b[i];
  fft(a, s, -1);
  
  // 處理卷積結果並進行 10000 進制進位
  for(int i = 0; i < s; ++i) {
    ans[i] += (ll)(a[i].real() + 0.5);  // 四捨五入
    if(ans[i] >= BASE) {
      ans[i+1] += ans[i] / BASE;
      ans[i] %= BASE;
    }
  }
  
  // 處理剩餘的進位
  for(int i = 0; i < s; ++i) {
    if(ans[i] >= BASE) {
      ans[i+1] += ans[i] / BASE;
      ans[i] %= BASE;
    }
  }
  
  // 找到最高非零位
  int pos = s;
  while(pos > 0 && ans[pos] == 0) --pos;
  
  // 輸出結果
  if(pos < 0) {
    cout << '0';
  } else {
    // 最高位直接輸出
    cout << ans[pos];
    // 輸出其餘位，需要補前導 0
    for(int i = pos-1; i >= 0; --i) {
      cout << setw(BASE_DIGITS) << setfill('0') << ans[i];
    }
  }
  cout << endl;
  return 0;
}