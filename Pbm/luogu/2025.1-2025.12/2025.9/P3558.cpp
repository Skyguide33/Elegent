//2025/9/24
#include <bits/stdc++.h>
using namespace std;

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
    
    inline void write(int x) {
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

int a[1000005], dp[3]; // -1:0 0:1 1:2

int main() {
  int n = read();
  for(int i = 0; i < 3; ++i) dp[i] = 100000001;
  for(int i = 1; i <= n; ++i) a[i] = read();
  dp[a[1]+1] = 0;
  for(int i = 2; i <= n; ++i) {
    if(a[i] == -1) {
      // dp[0]不变
      dp[1] = 100000001;
      dp[2] += 2;
    } else if(a[i] == 0) {
      dp[1] = min(dp[0], dp[1]);
      dp[0] += 1;
      dp[2] += 1;
    } else {
      dp[2] = min({dp[0], dp[1], dp[2]});
      dp[1] = dp[0]+1;
      dp[0] += 2;
    }
  }
  int ans = min({dp[0], dp[1], dp[2]});
  if(ans > 100000000) printf("BRAK\n");
  else write(ans), putchar('\n');
  return 0;
}