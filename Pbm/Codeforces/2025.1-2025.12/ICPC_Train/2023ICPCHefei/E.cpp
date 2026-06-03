//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

namespace FastIO {
    const int SZ = 1 << 20;
    char inbuf[SZ], outbuf[SZ];
    int in_left = 0, in_right = 0;
    int out_right = 0;
    
    inline void load() {
        int len = fread(inbuf, 1, SZ, stdin);
        in_left = 0;
        in_right = len;
    }
    
    inline char getchar() {
        if (in_left >= in_right) load();
        if (in_left >= in_right) return EOF;
        return inbuf[in_left++];
    }
    
    inline int read() {
        int x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9') ch = getchar();
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        return x;
    }
    
    inline void flush() {
        fwrite(outbuf, 1, out_right, stdout);
        out_right = 0;
    }
    
    inline void putchar(char ch) {
        outbuf[out_right++] = ch;
        if (out_right == SZ) flush();
    }
    
    inline void write(ll x) {
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
    
    struct Flusher {
        ~Flusher() { flush(); }
    } flusher;
}

using namespace FastIO;

int c[1001][1001], row[1000005], col[1000005], cntr[1000005], cntc[1000005]; 
ll prer[1000005], prec[1000005];
bool pd[1000005];

int main() {
  int n = read(), m = read();
  unordered_map<int, int> mp; int tot = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      c[i][j] = read();
      if(!mp.count(c[i][j])) mp[c[i][j]] = tot++;
    }
  }

  ll ans_c = 0, ans_r = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int idx = mp[c[i][j]];
      if(!pd[idx]) {
        row[idx] = 1; 
        pd[idx] = 1;
      } else ++row[idx];
    }
    for(int j = 1; j <= m; ++j) {
      int idx = mp[c[i][j]];
      if(pd[idx]) {
        ans_r += (cntr[idx]*i-prer[idx])*row[idx];
        prer[idx] += row[idx]*i;
        cntr[idx] += row[idx];
        pd[idx] = 0;
      }
    }
  }
  for(int j = 1; j <= m; ++j) {
    for(int i = 1; i <= n; ++i) {
      int idx = mp[c[i][j]];
      if(!pd[idx]) {
        col[idx] = 1; 
        pd[idx] = 1;
      } else ++col[idx];
    }
    for(int i = 1; i <= n; ++i) {
      int idx = mp[c[i][j]];
      if(pd[idx]) {
        ans_c += (cntc[idx]*j-prec[idx])*col[idx];
        prec[idx] += col[idx]*j;
        cntc[idx] += col[idx];
        pd[idx] = 0;
      }
    }
  }
  write((ans_r+ans_c)*2);
  return 0;
}