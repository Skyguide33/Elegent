//2026/6/2
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
        while (ch < '0' || ch > '9') {
            ch = getchar();
        }
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
    
    inline void write(int x) {
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
    
    struct Flusher {
        ~Flusher() { flush(); }
    } flusher;
}

using namespace FastIO;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n = read();
  vector<int> d(n+1), dp(n+1), q(n+1);
  for(int i = 1; i <= n; ++i) d[i] = read();
  int qq = read();
  while(qq--) {
    int k = read();
    int h = 1, t = 0;
    q[++t] = 1;
    for(int i = 2; i <= n; ++i) {
      if(q[h] < i-k) ++h;
      dp[i] = dp[q[h]]+(d[q[h]] <= d[i]);
      while(h <= t && (dp[q[t]] > dp[i] || (dp[q[t]] == dp[i] && d[q[t]] <= d[i]))) --t;
      q[++t] = i;
    }
    write(dp[n]); putchar('\n');
  }
  return 0;
}