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

int a[100005], b[100005];

void solve1() {
  int m = read(), n = read();
  for(ll i = 1; i <= m; ++i) a[i] = read();
  for(ll i = 1; i <= n; ++i) b[i] = read();
  sort(a+1, a+m+1); sort(b+1, b+n+1);
  int stu = 1, sch = 1;
  ll ans = 0;
  while(stu <= n && b[stu] <= a[1]) ans += a[1]-b[stu++];
  for(; stu <= n && sch < m; ++stu) {
    while(sch < m && !(b[stu] >= a[sch] && b[stu] <= a[sch+1])) ++sch;
    if(sch == m) break;
    else ans += min(b[stu]-a[sch], a[sch+1]-b[stu]);
  }
  while(stu <= n) ans += b[stu++]-a[m];
  write(ans);
}

void solve2() {
  int m = read(), n = read();
  for(ll i = 1; i <= m; ++i) a[i] = read();
  for(ll i = 1; i <= n; ++i) b[i] = read();
  sort(a+1, a+m+1);
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    int l = 0, r = m;
    while(l < r) {
      int mid = l + (r-l+1)/2;
      if(a[mid] <= b[i]) l = mid;
      else r = mid-1;
    }
    if(l == 0) ans += a[1] - b[i];
    else if(l == m) ans += b[i] - a[m];
    else ans += min(b[i]-a[l], a[l+1]-b[i]);
  }
  write(ans);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; //cin >> T;
  while(T--) solve2();
  return 0;
}