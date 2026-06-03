//2026/3/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

namespace FastIO {
  const int SZ = 1<<20;
  char inbuf[SZ], outbuf[SZ];
  int in_left = 0, in_right = 0;
  int out_right = 0;
  
  inline void load() {
    int len = fread(inbuf, 1, SZ, stdin);
    in_left = 0;
    in_right = len;
  }
  
  inline char getchar() {
    if(in_left >= in_right) load();
    if(in_left >= in_right) return EOF;
    return inbuf[in_left++];
  }
  
  inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if(ch == '-') f = -1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      x = x*10+(ch-'0');
      ch = getchar();
    }
    return x*f;
  }
  
  inline void flush() {
    fwrite(outbuf, 1, out_right, stdout);
    out_right = 0;
  }
  
  inline void putchar(char ch) {
    outbuf[out_right++] = ch;
    if(out_right == SZ) flush();
  }
  
  inline void write(int x) {
    if(x < 0) {
      putchar('-');
      x *= -1;
    }
    if(x > 9) write(x/10);
    putchar(x%10+'0');
  }
  
  struct Flusher {
    ~Flusher() { flush(); }
  } flusher;
}

using namespace FastIO;

int main() {
  int n = read(), ans = 0;
  while(n--) {
    int tt = read();
    ans += tt;
  }
  write(ans); putchar('\n');
  return 0;
}