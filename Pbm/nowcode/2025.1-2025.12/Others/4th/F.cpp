//2025/7/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long

namespace FastIO {
    const ll SZ = 1 << 20;
    char inbuf[SZ], outbuf[SZ];
    ll in_left = 0, in_right = 0;
    ll out_right = 0;
    
    inline void load() {
        ll len = fread(inbuf, 1, SZ, stdin);
        in_left = 0;
        in_right = len;
    }
    
    inline char getchar() {
        if (in_left >= in_right) load();
        if (in_left >= in_right) return EOF;
        return inbuf[in_left++];
    }
    
    inline ll read() {
        ll x = 0, f = 1;
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

ll a[300005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n = read(), k = read(), c = read();
  for(ll i = 1; i <= n; ++i) a[i] = read() - c*i;
  sort(a+1, a+n+1);
  ll ans = 0;
  for(ll i = n-k+1; i <= n; ++i) ans += a[i];
  write(ans+(k+1)*k/2*c);
  return 0;
}