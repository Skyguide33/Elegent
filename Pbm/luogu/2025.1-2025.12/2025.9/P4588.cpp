//2025/9/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ls p<<1
#define rs p<<1|1
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

ll a[100005], MOD;
ll tree[100005<<2];
int n;

void push_up(int p) {
  tree[p] = tree[ls]*tree[rs]%MOD;
}

void build(int p, int pl, int pr) {
  if(pl == pr) {
    tree[p] = a[pl];
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid);
  build(rs, mid+1, pr);
  push_up(p);
}

void update(int pos, int p, int pl, int pr) {
  if(pl == pr) {
    tree[p] = 1;
    return;
  }
  int mid = (pl+pr)>>1;
  if(pos <= mid) update(pos, ls, pl, mid);
  else update(pos, rs, mid+1, pr);
  push_up(p);
}

ll query(int R, int p, int pl, int pr) {
  if(pr <= R) return tree[p];
  int mid = (pl+pr)>>1;
  ll res = 1;
  res = query(R, ls, pl, mid)%MOD;
  if(R > mid) res = res*query(R, rs, mid+1, pr)%MOD;
  return res;
}

struct quest { int op, m, pa; } q[100005];

void solve() {
  int Q = read(); MOD = read();
  n = 0;
  for(int i = 1; i <= Q; ++i) {
    q[i].op = read(); q[i].m = read();
    if(q[i].op == 1) {
      q[i].pa = ++n;
      a[n] = q[i].m;
    } else {
      q[i].pa = q[q[i].m].pa;
    }
  }
  build(1, 1, n);
  int r = 0;
  for(int i = 1; i <= Q; ++i) {
    if(q[i].op == 1) ++r;
    else update(q[i].pa, 1, 1, n);
    write(query(r, 1, 1, n)); putchar('\n');
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = read();
  while(T--) solve();
  return 0;
}