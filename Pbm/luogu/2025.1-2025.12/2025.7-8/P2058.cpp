//2025/8/23
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
        int x = 0;
        char ch = getchar();
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

int b[100005];

struct p {
  int t; vector<int> v;
};

int main() {
  int n = read(), ans = 0; 
  queue<p> a;
  while(n--) {
    a.push({read(), vector<int>(read())});
    for(int& x: a.back().v)
      if(++b[x=read()] == 1) ++ans;
    while(a.back().t-a.front().t >= 86400) {
      for(int& x: a.front().v) 
        if(--b[x] == 0) --ans;
      a.pop();
    }
    write(ans); putchar('\n');
  }
  return 0;
}