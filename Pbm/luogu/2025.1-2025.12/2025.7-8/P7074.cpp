//2025/8/12
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

ll a[1005][1005], dp[1005][1005][2];

int main() {
  int n = read(), m = read();
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) a[i][j] = read();
  for(int i = 1; i <= n; ++i) dp[i][1][0] = dp[i][1][1] = a[i][1]+dp[i-1][1][0];
  for(int j = 2; j <= m; ++j) {
    dp[0][j][1] = dp[n+1][j][0] = LLONG_MIN;
    for(int i = 1; i <= n; ++i) {
      dp[i][j][1] = max({dp[i][j-1][0], dp[i][j-1][1], dp[i-1][j][1]})+a[i][j];
    }
    for(int i = n; i >= 1; --i) {
      dp[i][j][0] = max({dp[i][j-1][0], dp[i][j-1][1], dp[i+1][j][0]})+a[i][j];
    }
  }
  write(max(dp[n][m][0], dp[n][m][1]));
  return 0;
}