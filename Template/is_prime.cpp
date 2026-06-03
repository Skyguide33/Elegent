//2025/8/11
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

set<ll> vis;
set<ll> prime;

void E_sieve(ll n) {
  for(ll i = 2; i*i <= n; ++i) {
    if(!vis.count(i)) {
      for(int j = i*2; j <= n; j += i) vis.insert(j);
    }
  }
  for(int i = 2; i <= n; ++i) {
    if(!vis.count(i)) {
      write(i); putchar(' ');
    }
  }
  putchar('\n');
}

void euler_sieve(ll n) {
  int t;
  for(ll i = 2; i <= n; ++i) {
    if(!vis.count(i)) prime.insert(i);
    for(auto& x: prime) {
      t = i*x;
      if(t > n) break;
      vis.insert(t);
      if(i%x == 0) break; 
    }
  }
  for(auto& x: prime) {
    write(x); putchar(' ');
  }
  putchar('\n');
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n = read();
  // E_sieve(n);
  euler_sieve(n);
  return 0;
}


