//2025/9/24
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

ll a[100005], pd[320], MOD;
int n, block, t, pos[100005], st[320], ed[320];

struct quest { int op, m, pa; } q[100005];

void init() {
  block = pow(n, 1./2);
  t = n/block;
  if(n%block) ++t;
  for(int i = 1; i <= n; ++i) pos[i] = (i-1)/block+1;
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block+1;
    ed[i] = i*block;
  }
  ed[t] = n;
  for(int i = 1; i <= t; ++i) {
    pd[i] = a[st[i]];
    for(int j = st[i]+1; j <= ed[i]; ++j) pd[i] = pd[i]*a[j]%MOD;
  }
}

void change(int p) {
  a[p] = 1;
  p = pos[p];
  pd[p] = a[st[p]];
  for(int i = st[p]+1; i <= ed[p]; ++i) {
    pd[p] = pd[p]*a[i]%MOD;
  }
}

ll query(int r) {
  int p = pos[r];
  ll res = 1;
  if(p == 1) {
    for(int i = 1; i <= r; ++i) res = res*a[i]%MOD;
  } else {
    for(int i = 1; i < p; ++i) res = res*pd[i]%MOD;
    for(int i = st[p]; i <= r; ++i) res = res*a[i]%MOD;
  }
  return res;
}

void solve() {
  int Q = read(); MOD = read();
  n = 0;
  for(int i = 1; i <= Q; ++i) {
    q[i].op = read(); q[i].m = read();
    if(q[i].op == 1) {
      q[i].pa = ++n;
      a[n] = q[i].m;
    } else q[i].pa = q[q[i].m].pa;
  }
  init();
  int r = 0;
  for(int i = 1; i <= Q; ++i) {
    if(q[i].op == 1) ++r;
    else change(q[i].pa);
    write(query(r)); putchar('\n');
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = read();
  while(T--) solve();
  return 0;
}