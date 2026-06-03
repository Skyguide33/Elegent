//2025/10/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

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

int a[N], mp[N], root[N], cnt;
struct {
  int L, R, sum, ver;
} tree[N<<6];

void update(int rt, int ver, int pl, int pr, int num, int op) {
  tree[rt].ver = ver;
  tree[rt].sum += op;
  if(pl < pr) {
    int mid = (pl+pr)>>1;
    if(num <= mid) {
      if(tree[tree[rt].L].ver != ver) {
        int n_rt = ++cnt;
        tree[n_rt] = tree[tree[rt].L]; 
        tree[rt].L = n_rt;
      }
      update(tree[rt].L, ver, pl, mid, num, op);
    } else {
      if(tree[tree[rt].R].ver != ver) {
        int n_rt = ++cnt;
        tree[n_rt] = tree[tree[rt].R];
        tree[rt].R = n_rt;
      }
      update(tree[rt].R, ver, mid+1, pr, num, op);
    }
  }
}

int query(int rt, int pl, int pr, int L, int R) {
  if(L <= pl && pr <= R) return tree[rt].sum;
  int mid = (pl+pr)>>1, res = 0;
  if(L <= mid) res += query(tree[rt].L, pl, mid, L, R);
  if(R > mid) res += query(tree[rt].R, mid+1, pr, L, R);
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0); 
  int n = read();
  for(int i = 1; i <= n; ++i) a[i] = read();
  for(int i = n; i >= 1; --i) {
    root[i] = ++cnt;
    tree[root[i]] = tree[root[i+1]];
    if(mp[a[i]]) update(root[i], i, 1, n, mp[a[i]], -1);
    update(root[i], i, 1, n, i, 1);
    mp[a[i]] = i;
  }
  int m = read();
  while(m--) {
    int l = read(), r = read();
    write(query(root[l], 1, n, 1, r)); putchar('\n');
  }
  return 0;
}