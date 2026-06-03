//2025/9/23
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

int a[1000005], pos[1000005], st[1005], ed[1005], num[1000005], ans[1000005];

struct quest {
  int id, l, r;
} q[1000005];

bool cmp(quest &x, quest &y) {
  if(pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
  if(pos[x.l]%2) return x.r < y.r;
  return x.r > y.r;
  
}

int main() {
  int n = read();
  for(int i = 1; i <= n; ++i) a[i] = read();
  int block = sqrt(n), t = n/block;
  if(n%block) ++t;
  for(int i = 1; i <= n; ++i) pos[i] = (i-1)/block+1;
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block+1;
    ed[i] = i*block;
  }
  ed[t] = n;
  int m = read();
  for(int i = 1; i <= m; ++i) q[i] = {i, read(), read()};
  sort(q+1, q+m+1, cmp);
  int l = 1, r = 0, res = 0;
  for(int i = 1; i <= m; ++i) {
    while(l < q[i].l) {
      if(num[a[l]] == 1) --res;
      --num[a[l++]];
    }
    while(l > q[i].l) {
      ++num[a[--l]];
      if(num[a[l]] == 1) ++res;
    }
    while(r < q[i].r) {
      ++num[a[++r]];
      if(num[a[r]] == 1) ++res;
    }
    while(r > q[i].r) {
      if(num[a[r]] == 1) --res;
      --num[a[r--]];
    }
    ans[q[i].id] = res;
  }
  for(int i = 1; i <= m; ++i) write(ans[i]), putchar('\n');
  return 0;
}