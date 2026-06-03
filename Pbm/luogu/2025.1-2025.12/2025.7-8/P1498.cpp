//2025/7/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        int x = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        return x * f;
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
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
    
    struct Flusher {
        ~Flusher() { flush(); }
    } flusher;
}

using namespace FastIO;

char a[1025][2050];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n = read();
  for(int i = 0; i < (1<<n); ++i) 
    for(int j = 0; j < (1<<(n+1)); ++j) a[i][j] = ' ';
  a[0][0] = '/', a[0][1] = a[0][2] = '_', a[0][3] = '\\';
  a[1][1] = '/', a[1][2] = '\\';
  int len = 4, k = 1;
  while(k < n) {
    for(int i = 0; i < len/2; ++i)
      for(int j = 0; j < len; ++j) a[i][j+len] = a[i+len/2][j+len/2] = a[i][j];
    len *= 2; ++k;
  }
  for(int i = (1<<n)-1; i >= 0; --i) {
    for(int j = 0; j < (1<<(n+1)); ++j) putchar(a[i][j]);
    putchar('\n');
  }
  return 0;
}