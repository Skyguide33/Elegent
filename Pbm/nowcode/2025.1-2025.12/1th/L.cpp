//2025/7/16
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

struct MyCompare {  
  bool operator()(const ll& a, const ll& b) const { 
    return std::abs(a) > std::abs(b);  
  }  
}; 

void solve() {
  int n = read(), q = read();
  vector<ll> a(n+1);
  for(int i = 1; i <= n; ++i) a[i] = read();
  vector<ll> b(a);
  sort(a.begin(), a.end());
  map<ll, ll, MyCompare> small_num;
  map<ll, ll> large_num;
  int mid = n - n/2;
  int i = 1;
  while(i <= mid) {
    auto it = small_num.find(a[i]);
    if(it == small_num.end()) small_num[a[i]] = 1;
    else ++it->second;
    ++i;
  }
  while(i <= n) {
    auto it = large_num.find(a[i]);
    if(it == large_num.end()) large_num[a[i]] = 1;
    else ++it->second;
    ++i;
  }
  while(q--) {
    int ans = mid;
    ll p = read(), v = read();
    ll old1 = b[p], new1 = b[p]+v;
    b[p] = new1;
    ll mid_num = small_num.begin()->first;
    if(old1 <= mid_num) {
      if(--small_num[old1] == 0) small_num.erase(old1);
      if(new1 <= mid_num) {
        if(!small_num.count(new1)) small_num[new1] = 1;
        else ++small_num[new1];
      } else {
        if(!large_num.count(new1)) large_num[new1] = 1;
        else ++large_num[new1];
        ll temp = large_num.begin()->first;
        if(--large_num[temp] == 0) large_num.erase(temp);
        if(!small_num.count(temp)) small_num[temp] = 1;
        else ++small_num[temp];
      }
    } else {
      if(--large_num[old1] == 0) large_num.erase(old1);
      if(!large_num.count(new1)) large_num[new1] = 1;
      else ++large_num[new1];
    }
    if(small_num.begin()->first == large_num.begin()->first)
      ans -= small_num.begin()->second;
    write(ans); putchar('\n');
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = read();
  while(T--) solve();
  return 0;
}