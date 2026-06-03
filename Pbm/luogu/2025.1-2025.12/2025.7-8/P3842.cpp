//2025/7/
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

int dp[2][2], a[2][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  short n = read();
  a[0][0] = a[0][1] = 1; dp[0][0] = dp[0][1] = -1;
  bool now = 0, old = 1;
  for(short i = 1; i <= n; ++i) {
    swap(now, old);
    a[now][0] = read(), a[now][1] = read();
    dp[now][0] = min(dp[old][0]+abs(a[now][1]-a[old][0]), dp[old][1]+abs(a[now][1]-a[old][1]))+1+a[now][1]-a[now][0];
    dp[now][1] = min(dp[old][0]+abs(a[now][0]-a[old][0]), dp[old][1]+abs(a[now][0]-a[old][1]))+1+a[now][1]-a[now][0];
  }
  write(min(dp[now][1]-a[now][1],dp[now][0]-a[now][0])+n);
  return 0;
}