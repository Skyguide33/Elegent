#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define ls p<<1
#define rs p<<1|1
#define up(p, y) p = max(p, y) 
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
            x = x* 10 + (ch - '0');
            ch = getchar();
        }
        return x* f;
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

const int N = 5e5+5, inf = 1e9; 
int n, m; 

struct node {
  int len, mx, hmx, smx, cnt; ll sum; 
  int tag1, htag1, tag2, htag2; 
} t[N<<2]; 

inline void update(int p) {
  t[p].mx = max(t[ls].mx, t[rs].mx); t[p].hmx = max(t[ls].hmx, t[rs].hmx); 
  t[p].smx = max(t[ls].smx, t[rs].smx); t[p].sum = t[ls].sum+t[rs].sum; 
  t[p].cnt = 0; 
  if(t[p].mx == t[ls].mx) t[p].cnt += t[ls].cnt; 
  else up(t[p].smx, t[ls].mx); 
  if(t[p].mx == t[rs].mx) t[p].cnt += t[rs].cnt; 
  else up(t[p].smx, t[rs].mx); 
}

inline void pushtag(int p, int tag1, int htag1, int tag2, int htag2) {
  t[p].sum += 1ll*t[p].cnt*tag1+1ll*(t[p].len-t[p].cnt)*tag2; 
  up(t[p].hmx, t[p].mx+htag1); t[p].mx += tag1; 
  if(t[p].smx != -inf) t[p].smx += tag2; 
  up(t[p].htag1, t[p].tag1+htag1); up(t[p].htag2, t[p].tag2+htag2); 
  t[p].tag1 += tag1; t[p].tag2 += tag2; 
}

inline void pushdown(int p) {
  int mx = max(t[ls].mx, t[rs].mx); 
  int &t1 = t[p].tag1, &ht1 = t[p].htag1, &t2 = t[p].tag2, &ht2 = t[p].htag2; 
  if(!(t1 || ht1 || t2 || ht2)) return; 
  if(t[ls].mx == mx) pushtag(ls, t1, ht1, t2, ht2); 
  else pushtag(ls, t2, ht2, t2, ht2); 
  if(t[rs].mx == mx) pushtag(rs, t1, ht1, t2, ht2); 
  else pushtag(rs, t2, ht2, t2, ht2); 
  t1 = ht1 = t2 = ht2 = 0; 
}

void build(int p, int pl, int pr) {
  t[p].len = pr-pl+1; 
  if(pl == pr) {
    t[p].cnt = 1; t[p].sum = t[p].mx = t[p].hmx = read(); 
    t[p].smx = -inf; return; 
  }
  int mid = (pl+pr)>>1; 
  build(ls, pl, mid); build(rs , mid+1, pr); 
  update(p); 
}

void modify_add(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) return pushtag(p, d, d, d, d); 
  int mid = (pl+pr)>>1; pushdown(p); 
  if(L <= mid) modify_add(L, R, ls, pl, mid, d); 
  if(mid < R) modify_add(L, R, rs, mid+1, pr, d); 
  update(p); 
}

void modify_min(int L, int R, int p, int pl, int pr, int x) {
  if(x >= t[p].mx) return; 
  if(L <= pl && pr <= R && t[p].smx < x) return pushtag(p, x-t[p].mx, 0, 0, 0); 
  int mid = (pl+pr)>>1; pushdown(p); 
  if(L <= mid) modify_min(L, R, ls, pl, mid, x); 
  if(mid < R) modify_min(L, R, rs, mid+1, pr, x); 
  update(p); 
}

ll query_sum(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return t[p].sum; 
  int mid = (pl+pr)>>1; pushdown(p); ll s = 0; 
  if(L <= mid) s = query_sum(L, R, ls, pl, mid); 
  if(mid < R) s += query_sum(L, R, rs, mid+1, pr); 
  return s; 
}

int query_max(int L, int R, int p, int pl, int pr, bool tp) {
  if(L <= pl && pr <= R) return tp? t[p].hmx: t[p].mx; 
  int mid = (pl+pr)>>1, ans = -inf; pushdown(p); 
  if(L <= mid) ans = query_max(L, R, ls, pl, mid, tp); 
  if(mid < R) up(ans, query_max(L, R, rs, mid+1, pr, tp)); 
  return ans; 
}

int main() {
  n = read(); m = read(); 
  build(1, 1, n); 
  while(m--) {
    int op = read(), l = read(), r = read(); 
    if(op == 1) modify_add(l, r, 1, 1, n, read()); 
    else if(op == 2) modify_min(l, r, 1, 1, n, read()); 
    else if(op == 3) write(query_sum(l, r, 1, 1, n)), putchar('\n'); 
    else if(op == 4) write(query_max(l, r, 1, 1, n, 0)), putchar('\n');
    else write(query_max(l, r, 1, 1, n, 1)), putchar('\n'); 
  }
  return 0; 
}